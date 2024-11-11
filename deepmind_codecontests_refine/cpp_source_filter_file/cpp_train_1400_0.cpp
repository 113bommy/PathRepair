#include <bits/stdc++.h>
using namespace std;
template <class T>
T read1() {
  T t = 0;
  bool vis = 0;
  char k;
  do (k = getchar()) == '-' && (vis = 1);
  while ('0' > k || k > '9');
  while ('0' <= k && k <= '9')
    t = (t << 3) + (t << 1) + (k ^ '0'), k = getchar();
  return vis ? -t : t;
}
template <class T>
void print(T arg1) {
  cout << arg1;
}
template <class T>
void get(T arg1) {
  cout << arg1;
}
template <typename T, typename... Ts>
void print(T arg1, Ts... arg_left) {
  cout << arg1 << " ";
  print(arg_left...);
}
template <typename T, typename... Ts>
void get(T arg1, Ts... arg_left) {
  cout << arg1 << " ";
  print(arg_left...);
}
pair<int, int> a[405];
int s, dp[405][405];
pair<int, int> operator-(const pair<int, int> &x, const pair<int, int> &y) {
  return pair<int, int>(x.first - y.first, x.second - y.second);
}
long long operator*(const pair<int, int> &x, const pair<int, int> &y) {
  return 1ll * x.first * y.second - 1ll * x.second * y.first;
}
int main() {
  s = read1<int>();
  long long t = 0;
  for (int i = 1; i <= s; ++i) {
    a[i] = make_pair(read1<int>(), read1<int>());
    if (i != 1) t += a[i - 1] * a[i];
  }
  t += a[s] * a[1];
  for (int i = 1; i < s; ++i) dp[i][i + 1] = 1;
  if (t > 0) reverse(a + 1, a + s + 1);
  for (int i = s; --i;)
    for (int j = i + 2; j <= s; ++j)
      for (int k = i + 1; k < j; ++k)
        if ((a[j] - a[i]) * (a[k] - a[i]) > 0)
          dp[i][j] = (dp[i][j] + 1ll * dp[i][k] * dp[k][j]) % 100000007;
  printf("%d", dp[1][s]);
  return 0;
}
