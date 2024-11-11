#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < ((int)((t).size())); i++) s << t[i] << " ";
  return s;
}
long long n, c[1000], ans = 1, visit[1000], d, res;
int dfs(int v, int start, int step) {
  if (v == start) return step;
  visit[v] = true;
  if (!visit[c[v]])
    return dfs(c[v], start, step + 1);
  else
    return -1;
}
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  {
    bool flag = true;
    ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) visit[j] = false;
      if (c[i] != i) {
        res = dfs(c[i], i, 1);
        if (res == -1) {
          flag = false;
          break;
        } else if (res % 2 == 0)
          res /= 2;
        d = gcd(res, ans);
        ans *= res;
        ans /= d;
      }
    }
    if (flag)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
