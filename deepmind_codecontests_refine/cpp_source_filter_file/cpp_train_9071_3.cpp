#include <bits/stdc++.h>
using namespace std;
long long int v[100];
long long int esum(long long int n) {
  return ((n % 1000000007) * ((n + 1) % 1000000007)) % 1000000007;
}
long long int odsum(long long int n) {
  return ((n % 1000000007) * (n % 1000000007)) % 1000000007;
}
void solve() {
  long long int a, b;
  cin >> a >> b;
  long long int sum = 0;
  long long int es = 0, os = 0, e = 0, o = 0;
  for (long long int i = 1;; i++) {
    sum += v[i];
    if (i & 1)
      o += v[i];
    else
      e += v[i];
    if (!es || !os) {
      if (sum >= a) {
        long long int ex = sum - a;
        if (i % 2 == 0)
          es = e - ex, os = o + 1;
        else
          os = o - ex, es = e + 1;
      }
    }
    if (sum >= b) {
      long long int ex = sum - b;
      if (i % 2 == 0)
        e -= ex;
      else
        o -= ex;
      break;
    }
  }
  long long int an = 0;
  an += esum(e);
  an %= 1000000007;
  an += odsum(o);
  an %= 1000000007;
  an -= esum(es - 1);
  if (an < 0) an += 1000000007;
  an -= odsum(os - 1);
  if (an < 0) an += 1000000007;
  cout << an << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  v[1] = 1;
  for (long long int i = 2; i <= 42; i++) {
    v[i] = v[i - 1] * 2;
  }
  solve();
  return 0;
}
