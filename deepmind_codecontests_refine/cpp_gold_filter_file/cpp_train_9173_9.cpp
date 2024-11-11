#include <bits/stdc++.h>
using namespace std;
const long long base = 998244353;
int n;
long long kq;
int main() {
  scanf("%d", &n);
  kq = 1;
  for (int i = 1; i <= n; i++) kq = (kq * i) % base;
  long long tmp = 1;
  for (int i = 1; i <= n - 2; i++) {
    tmp = (tmp * (n - i + 1)) % base;
    long long z = (1ll * (n - 1 - i) * i) % base;
    kq = (kq + (tmp * z) % base) % base;
  }
  cout << kq << endl;
}
