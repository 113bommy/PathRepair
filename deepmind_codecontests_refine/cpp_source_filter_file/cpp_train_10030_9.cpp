#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long t = a;
  a = max(a, b);
  b = min(t, b);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long phi(long long n) {
  long long res = 0;
  for (size_t i = 0; i < n; i++) {
    if (gcd(i, n) == 1) res++;
  }
  return res;
}
int main(int argc, char const *argv[]) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int a, b, r;
  cin >> a >> b >> r;
  if (r * 2 >= min(a, b)) {
    cout << "First";
  } else {
    cout << "Second";
  }
  return 0;
}
