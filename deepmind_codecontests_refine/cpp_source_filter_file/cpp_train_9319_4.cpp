#include <bits/stdc++.h>
using namespace std;
long long n, a[1005], b[1005], ansa, ansb;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) {
    long long cnta = a[i], cntb = b[i];
    for (int j = i + 1; j <= n; j++) {
      cnta |= a[j];
      cntb |= b[j];
      ansa = max(ansa, cnta);
      ansb = max(ansb, cntb);
    }
  }
  cout << ansa + ansb;
}
