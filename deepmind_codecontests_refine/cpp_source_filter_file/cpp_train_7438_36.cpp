#include <bits/stdc++.h>
using namespace std;
const int MAX = 901;
int n, r;
int s;
vector<pair<int, int> > p;
vector<int> candidate;
int res = 0;
vector<int> ret;
int getDist(int x1, int x2, int y1, int y2) {
  return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}
void backtrack(int start, int len, int dist) {
  if (len >= n) {
    if (res < dist) {
      res = dist;
      ret = candidate;
    }
    return;
  }
  for (int i = start; i < s; ++i) {
    int t = dist;
    for (int j = 0; j < (int)candidate.size(); ++j)
      t += getDist(p[i].first, p[candidate[j]].first, p[i].second,
                   p[candidate[j]].second);
    candidate.push_back(i);
    backtrack(i, len + 1, t);
    candidate.pop_back();
  }
}
bool cmp(pair<int, int> A, pair<int, int> B) {
  return ((A.first) * (A.first)) + ((A.second) * (A.second)) >
         ((B.first) * (B.first)) + ((B.second) * (B.second));
}
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin >> n >> r;
  for (int i = 0; i <= r; ++i) {
    for (int j = 0; j <= r; ++j) {
      if (((i) * (i)) + ((j) * (j)) <= ((r) * (r))) {
        p.push_back(pair<int, int>(i, j));
        if (i) p.push_back(pair<int, int>(-i, j));
        if (j) p.push_back(pair<int, int>(i, -j));
        if (i && j) p.push_back(pair<int, int>(-i, -j));
      }
    }
  }
  sort(p.begin(), p.end(), cmp);
  s = min((int)p.size(), 15);
  backtrack(0, 0, 0);
  cout << res << "\n";
  for (int i = 0; i < n; ++i)
    cout << p[ret[i]].first << " " << p[ret[i]].second << "\n";
}
