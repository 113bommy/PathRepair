#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
const int SQ = 320;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
map<string, int> mp, res;
vector<int> vec[4 * maxN];
int main() {
  time_t START = clock();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "";
  for (char ch = getchar(); ch != '\n'; ch = getchar()) s += ch;
  int n = s.size(), cnt = 0;
  for (int i = 0; i < n; i++) {
    string t = "";
    for (int len = 0; len < 4 && i + len < n; len++) {
      t += s[i + len];
      if (!mp[t]) mp[t] = cnt++;
      vec[mp[t]].push_back(i);
    }
  }
  int q;
  scanf("%d\n", &q);
  while (q--) {
    string a = "", b = "";
    for (char ch = getchar(); ch != ' '; ch = getchar()) a += ch;
    for (char ch = getchar(); ch != '\n'; ch = getchar()) b += ch;
    string R = min(a, b) + '*' + max(a, b);
    int x = mp[a], y = mp[b];
    if (!x || !y) {
      printf("-1\n");
      continue;
    }
    if (!res[R]) {
      if ((int)vec[x].size() < (int)vec[y].size()) {
        swap(a, b);
        swap(x, y);
      }
      int ans = n;
      if (SQ <= (int)vec[y].size()) {
        int ix = 0;
        for (int i : vec[y]) {
          while (ix < (int)vec[x].size() && vec[x][ix] < i) ix++;
          if (ix < (int)vec[x].size())
            ans = min(ans, max(i + (int)b.size(), vec[x][ix] + (int)a.size()) -
                               min(i, vec[x][ix]));
          if (ix > 0)
            ans = min(ans,
                      max(i + (int)b.size(), vec[x][ix - 1] + (int)a.size()) -
                          min(i, vec[x][ix - 1]));
        }
      } else
        for (int i : vec[y]) {
          int ix =
              lower_bound(vec[x].begin(), vec[x].end(), i) - vec[x].begin();
          if (ix < (int)vec[x].size())
            ans = min(ans, max(i + (int)b.size(), vec[x][ix] + (int)a.size()) -
                               min(i, vec[x][ix]));
          if (ix > 0)
            ans = min(ans,
                      max(i + (int)b.size(), vec[x][ix - 1] + (int)a.size()) -
                          min(i, vec[x][ix - 1]));
        }
      res[R] = ans;
    }
    printf("%d\n", res[R]);
  }
  time_t FINISH = clock();
  cerr << "Execution time: "
       << (long double)(FINISH - START) / CLOCKS_PER_SEC * 1000.0
       << " milliseconds.\n";
  return 0;
}
