#include <bits/stdc++.h>
using namespace std;
long long mul[10005000];
long long ar[3000000];
long long pp(int n) {
  long long x = 0;
  while (n != 1) {
    n /= 4;
    x++;
  }
  return x;
}
int n;
void oo(int str, int endd, int value) {
  if (endd >= n || value == 0) return;
  for (int i = str; i <= endd; i++) mul[i] = value;
  oo(endd + 1, endd + (endd + 1) * 3, value - 1);
}
int main() {
  cin >> n;
  int j = pp(n);
  for (int i = 0; i < n; i++) scanf("&%I64d", ar[i]);
  if (n == 1) {
    cout << ar[0];
    return 0;
  }
  sort(ar, ar + n);
  reverse(ar, ar + n);
  mul[0] = j + 1;
  oo(1, 3, j);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += mul[i] * ar[i];
  }
  cout << ans;
  return 0;
}
