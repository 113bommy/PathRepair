#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Read(T &x) {
  int f = 1;
  char t = getchar();
  while (t < '0' || t > '9') {
    if (t == '-') f = -1;
    t = getchar();
  }
  x = 0;
  while (t >= '0' && t <= '9') {
    x = x * 10 + t - '0';
    t = getchar();
  }
  x *= f;
}
template <typename T>
inline void Write(T x) {
  static int output[20];
  int top = 0;
  if (x < 0) putchar('-'), x = -x;
  do {
    output[++top] = x % 10;
    x /= 10;
  } while (x > 0);
  while (top > 0) putchar('0' + output[top--]);
  putchar('\n');
}
template <typename T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
template <typename T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
const int maxn = 10005;
int n;
char s[maxn];
bool f[maxn][2];
vector<string> ans;
void input() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
}
void solve() {
  f[n + 1][0] = f[n + 1][1] = 1;
  for (int i = n; i > 5; i--) {
    f[i][0] |= f[i + 2][1];
    if (s[i] != s[i + 2] || s[i + 1] != s[i + 3]) f[i][0] |= f[i + 2][0];
    f[i][1] |= f[i + 3][0];
    if (s[i] != s[i + 3] || s[i + 2] != s[i + 4] || s[i + 3] != s[i + 5])
      f[i][1] |= f[i + 3][1];
    if (f[i][0]) {
      string res;
      res.push_back(s[i]);
      res.push_back(s[i + 1]);
      ans.push_back(res);
    }
    if (f[i][1]) {
      string res;
      res.push_back(s[i]);
      res.push_back(s[i + 1]);
      res.push_back(s[i + 2]);
      ans.push_back(res);
    }
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << endl;
  }
}
int main() {
  input();
  solve();
  return 0;
}
