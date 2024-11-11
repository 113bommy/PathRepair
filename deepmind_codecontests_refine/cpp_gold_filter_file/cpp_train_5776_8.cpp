#include <bits/stdc++.h>
using namespace std;
long double a[500005], b[500005];
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int l = s.length(), mid;
  mid = (l + 1) / 2;
  for (int i = 1; i <= l; i++) {
    a[i] = 1.0 / i + a[i - 1];
  }
  for (int i = 1; i <= mid; i++) {
    b[i] = b[i - 1] + a[l - i + 1] - a[i - 1];
  }
  int i = mid;
  if (l % 2) i--;
  for (int j = mid + 1; j <= l; j++, i--) {
    b[j] = b[i];
  }
  double ans = 0;
  for (int i = 1; i <= l; i++) {
    char c = s[i - 1];
    if (c == 'A' || c == 'I' || c == 'O' || c == 'E' || c == 'U' || c == 'Y')
      ans = ans + b[i];
  }
  printf("%.15f\n", ans);
  return 0;
}
