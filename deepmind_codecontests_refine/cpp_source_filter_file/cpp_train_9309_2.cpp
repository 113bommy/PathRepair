#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e5 + 4;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, l, r;
    scanf("%lld", &n);
    scanf("%lld", &l);
    scanf("%lld", &r);
    long long k = n / l;
    if (k * r >= n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
