#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 1e5 + 5;
int N;
LL A, B, K;
LL gcd(LL, LL);
int main() {
  cin >> A >> B;
  if (A > B) swap(A, B);
  B = B - A;
  int top = sqrt(B);
  LL minn = A * (A + B) / gcd(A, B);
  for (int i = 1; i <= top; i++) {
    if (B % i == 0) {
      LL tmp, k;
      k = i - A % i;
      tmp = (A + k) * (A + B * k) / gcd(A + k, B);
      if (minn > tmp) minn = tmp, K = k;
      if (minn == tmp) K = min(K, k);
      k = (B / i) - A % (B / i);
      tmp = (A + k) * (A + B * k) / gcd(A + k, B);
      if (minn > tmp) minn = tmp, K = k;
      if (minn == tmp) K = min(K, k);
    }
  }
  cout << K << endl;
  return 0;
}
LL gcd(LL a, LL b) { return (!b) ? a : gcd(b, a % b); }
