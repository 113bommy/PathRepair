#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
typedef vector<vector<int> > VVI;
inline int mult(int x, int y) { return ((long long)x * y) % 1000000007; }
int power(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = mult(ret, x);
    x = mult(x, x);
    y = y / 2;
  }
  return ret;
}
int gcd(int a, int b) {
  if (b) return gcd(b, a % b);
  return a;
}
vector<int> prime;
void generateprime(int n) {
  int i, j;
  vector<int> num(n + 5);
  num[1] = 1;
  for (i = 4; i < n; i = i + 2) num[i] = 1;
  for (i = 3; i < n; i++) {
    if (num[i] == 0) {
      for (j = 3 * i; j < n; j = j + 2 * i) num[j] = 1;
    }
  }
  num[0] = 0;
  for (i = 2; i < n; i++) {
    if (num[i] == 0) prime.push_back(i);
    num.clear();
  }
}
int main() {
  char str[500005];
  long long len, i;
  double temp = 0, ans = 0, dp[500005];
  scanf("%s", str);
  len = strlen(str);
  for (i = 1; i <= len; i++) {
    temp = temp + (double)1 / i;
  }
  dp[0] = 0;
  for (i = 1; i <= len; i++) {
    dp[i] = dp[i - 1] + temp;
    temp = temp - (double)1 / i - (double)1 / (len - i + 1);
  }
  for (i = 0; i < len; i++) {
    if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
        str[i] == 'U' || str[i] == 'Y')
      ans = ans + dp[min(i + 1, len - i)];
  }
  cout << setprecision(8);
  cout << fixed;
  cout << ans << endl;
  return 0;
}
