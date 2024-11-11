#include <bits/stdc++.h>
using namespace std;
long long gcd(long long A, long long B) {
  if (B == 0)
    return A;
  else
    return gcd(B, A % B);
}
int main() {
  long long t, a, b, te;
  scanf("%I64d", &t);
  scanf("%I64d", &a);
  scanf("%I64d", &b);
  long long ans = min(t, min(a, b) - 1);
  te = t;
  long long g = gcd(a, b);
  long long tmpa = a / g;
  if (5000000000000000000 / tmpa < b) {
    ans = ans;
  } else {
    long long ind = t / (tmpa * b);
    if (ind != 0) ans += (ind - 1) * min(a, b);
    long long extra = t % (tmpa * b);
    if (ind != 0) ans += (min(extra + 1, min(a, b)));
  }
  long long ex = gcd(ans, te);
  long long num = ans / ex;
  long long den = te / ex;
  cout << num << "/" << den << endl;
  return 0;
}
