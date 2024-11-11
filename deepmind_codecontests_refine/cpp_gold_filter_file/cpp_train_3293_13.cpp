#include <bits/stdc++.h>
using namespace std;
string Convert(double number) {
  ostringstream buff;
  buff << number;
  return buff.str();
}
bool comp(int a, int b) { return (a < b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  int samp1;
  cin >> samp1;
  v.push_back(make_pair(samp1, 1));
  for (int i = 1; i < n; ++i) {
    cin >> samp1;
    if (v[v.size() - 1].first == samp1) {
      v[v.size() - 1].second++;
    } else {
      v.push_back(make_pair(samp1, 1));
    }
  }
  priority_queue<pair<int, int> > g;
  int prev[v.size()], nxt[v.size()];
  for (int i = 0; i < v.size(); ++i) {
    if (i == 0) {
      prev[i] = 0;
      if (v.size() > 1) {
        nxt[i] = i + 1;
      } else {
        nxt[i] = 0;
      }
    } else if (i == v.size() - 1) {
      nxt[i] = i;
      if (v.size() > 1) {
        prev[i] = i - 1;
      } else {
        prev[i] = 0;
      }
    } else {
      prev[i] = i - 1;
      nxt[i] = i + 1;
    }
    g.push(make_pair(v[i].second, -i));
  }
  int cnt1 = v.size();
  long long count = 0;
  while (cnt1 > 0 && !g.empty()) {
    pair<int, int> sa = g.top();
    g.pop();
    if (v[-sa.second].second == 0) {
      continue;
    }
    int max_dist = -sa.second;
    if (prev[max_dist] == max_dist) {
      v[max_dist].second = 0;
      prev[nxt[max_dist]] = nxt[max_dist];
      cnt1--;
    } else if (nxt[max_dist] == max_dist) {
      nxt[prev[max_dist]] = prev[max_dist];
      v[max_dist].second = 0;
      cnt1--;
    } else {
      if (v[prev[max_dist]].first == v[nxt[max_dist]].first) {
        v[prev[max_dist]].second += v[nxt[max_dist]].second;
        g.push(make_pair(v[prev[max_dist]].second, -prev[max_dist]));
        v[nxt[max_dist]].second = 0;
        v[max_dist].second = 0;
        if (nxt[nxt[max_dist]] == nxt[max_dist]) {
          nxt[prev[max_dist]] = prev[max_dist];
        } else {
          nxt[prev[max_dist]] = nxt[nxt[max_dist]];
          prev[nxt[nxt[max_dist]]] = prev[max_dist];
        }
        cnt1 -= 2;
      } else {
        v[max_dist].second = 0;
        prev[nxt[max_dist]] = prev[max_dist];
        nxt[prev[max_dist]] = nxt[max_dist];
        cnt1--;
      }
    }
    count++;
  }
  cout << count << endl;
  return 0;
}
