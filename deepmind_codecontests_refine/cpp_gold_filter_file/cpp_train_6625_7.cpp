#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int have[300];
vector<int> pos[30];
int main() {
  ios_base::sync_with_stdio(0);
  string s1, s2;
  while (cin >> s1 >> s2) {
    int n = s1.length();
    int m = s2.length();
    memset(have, 0, sizeof(have));
    for (int i = 0; i < n; ++i) {
      have[s1[i]] = 1;
      pos[s1[i] - 'a'].push_back(i);
    }
    bool good = 1;
    for (int i = 0; i < m; ++i)
      if (!have[s2[i]]) good = 0;
    if (good) {
      int cnt = 0, cur = 0, idx = 0;
      while (cur < m) {
        idx = 0;
        ++cnt;
        while (cur < m) {
          idx = lower_bound(pos[s2[cur] - 'a'].begin(),
                            pos[s2[cur] - 'a'].end(), idx) -
                pos[s2[cur] - 'a'].begin();
          if (idx == pos[s2[cur] - 'a'].size()) break;
          idx = pos[s2[cur] - 'a'][idx] + 1;
          ++cur;
        }
      }
      cout << cnt << "\n";
    } else
      cout << "-1\n";
    for (int i = 0; i < 26; ++i) pos[i].clear();
  }
  return 0;
}
