#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1000000000;
template <class T>
T read(T &x) {
  char c;
  int flag = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag *= -1;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= flag;
  return x;
}
long long a[100005];
long long n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  long long sum = 0;
  sum += a[1] * (n - a[1] + 1) % MOD;
  for (int i = 2; i <= n; ++i) {
    if (a[i - 1] > a[i]) {
      sum += (a[i]) * (a[i - 1] - a[i]);
    } else if (a[i - 1] < a[i]) {
      sum += (a[i] - a[i - 1]) * (n - a[i] + 1);
    }
  }
  cout << sum << endl;
}
