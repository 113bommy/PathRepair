#include <bits/stdc++.h>
using namespace std;
long long powm(long long base, long long exp, long long mod = 1000000007) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % mod;
    exp >>= 1, base = (base * base) % mod;
  }
  return ans;
}
long long ctl(char x, char an = 'a') { return (long long)(x - an); }
char ltc(long long x, char an = 'a') { return (char)(x + an); }
long long a[1000005], y;
map<long long, long long> m;
pair<long long, long long> get(long long x) {
  return pair<long long, long long>((x - 1) / y + 1, (x - 1) % y + 1);
}
bool con(pair<long long, long long> x, pair<long long, long long> y) {
  return (abs(x.first - y.first) + abs(x.second - y.second) == 1);
}
int main() {
  long long n, width = -1;
  cin >> n;
  for (long long i = 1; i < n + 1; i++) cin >> a[i];
  for (long long i = 2; i < n + 1; i++) {
    if (abs(a[i] - a[i - 1]) != 1) {
      long long tmp = abs(a[i] - a[i - 1]);
      if (tmp == 0) return 0 * printf("NO\n");
      if (width == -1)
        width = tmp;
      else {
        if (tmp != width) return 0 * printf("NO\n");
      }
    }
  }
  long long bada = 1000000000;
  if (width == -1) {
    printf("YES\n");
    cout << bada << " " << bada;
    return 0;
  }
  y = width;
  for (long long i = 2; i < n + 1; i++) {
    if (abs(a[i] - a[i - 1]) != 1) {
      if (!con(get(a[i]), get(a[i - 1]))) {
        return 0 * printf("NO\n");
      }
    }
  }
  printf("YES\n");
  cout << bada << " " << y;
  return 0;
}
