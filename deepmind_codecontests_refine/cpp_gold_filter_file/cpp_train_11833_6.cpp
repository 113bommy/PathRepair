#include <bits/stdc++.h>
inline long long read() {
  long long sign = 1;
  long long x = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    if (ch == '-') sign = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * sign;
}
inline void wonl() { putchar('\n'); }
inline void ww(long long k) {
  if (k < 0) putchar('-'), k *= -1;
  char ch[20];
  int num = 0;
  while (k) ch[++num] = k % 10, k /= 10;
  if (num == 0) ch[++num] = 0;
  while (num) putchar(ch[num--] + '0');
}
using namespace std;
const int N = 1e5 + 4;
template <typename T, typename... V>
inline void wonl(T t, V... v) {
  ww(t);
  if (sizeof...(v)) putchar(' ');
  wonl(v...);
}
vector<string> rotate(vector<string> s) {
  int n = s[0].size();
  for (int x = 0; x < n / 2; x++) {
    for (int y = x; y < n - x - 1; y++) {
      char temp = s[x][y];
      s[x][y] = s[y][n - 1 - x];
      s[y][n - 1 - x] = s[n - 1 - x][n - 1 - y];
      s[n - 1 - x][n - 1 - y] = s[n - 1 - y][x];
      s[n - 1 - y][x] = temp;
    }
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<string> s(n), res(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) cin >> res[i];
  bool flag = 0;
  for (int i = 0; i < 5; i++) {
    if (res == s) {
      flag = 1;
      break;
    }
    res = rotate(res);
  }
  for (int i = 0; i < n; i++) reverse(res[i].begin(), res[i].end());
  for (int i = 0; i < 5; i++) {
    if (res == s) {
      flag = 1;
      break;
    }
    res = rotate(res);
  }
  if (flag)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
