#include <bits/stdc++.h>
using namespace std;
int canReach1(vector<pair<int, string> > &scores, vector<int> &b, int pos,
              int id, int rest) {
  int myscore = scores[id].first;
  if (b.size()) myscore += b[0];
  int t = b.size() - 1;
  for (int i = pos; i < id; i++) {
    int score = scores[i].first;
    if (rest > 0) {
      rest--;
    } else {
      score += b[t];
      t--;
    }
    if (score > myscore) return 0;
    if (score == myscore && scores[i].second < scores[id].second) return 0;
  }
  return 1;
}
int canReach2(vector<pair<int, string> > &scores, vector<int> &b, int pos,
              int id, int rest) {
  int myscore = scores[id].first;
  int t = b.size() - 1;
  if (rest == 0) {
    myscore += b[t];
    t--;
  }
  int cur = 0;
  for (int i = pos; i > id; i--) {
    int score = scores[i].first;
    if (cur <= t) {
      score += b[cur];
      cur++;
    }
    if (score < myscore) return 0;
    if (score == myscore && scores[i].second > scores[id].second) return 0;
  }
  return 1;
}
int cmp(const pair<int, string> &a, const pair<int, string> &b) {
  if (a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}
int main() {
  int n;
  cin >> n;
  vector<pair<int, string> > scores;
  for (int i = 0; i < n; i++) {
    string str;
    int pts;
    cin >> str >> pts;
    scores.push_back(make_pair(pts, str));
  }
  sort(scores.begin(), scores.end(), cmp);
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b.rbegin(), b.rend());
  string nick;
  cin >> nick;
  int id = 0;
  for (int i = 0; i < n; i++) {
    if (scores[i].second == nick) {
      id = i;
      break;
    }
  }
  int rest = n - m;
  int l = 0, r = id;
  int highest = id;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (canReach1(scores, b, mid, id, rest)) {
      highest = min(mid, highest);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  l = id, r = n - 1;
  int lowest = id;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (canReach2(scores, b, mid, id, rest)) {
      lowest = max(mid, lowest);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << highest + 1 << " " << lowest + 1 << endl;
  return 0;
}
