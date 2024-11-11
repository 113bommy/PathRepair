#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
double a[N], b[N];
char s[N];
int n, m;
int main() {
  scanf("%d%s", &n, &s);
  m = n;
  for (int i = 0; i < n; i++) a[i] = s[i] - '0';
  for (int i = 1; i < n; i++)
    if (m % i == 0) {
      while (i >= 2 && m % i == 0) m /= i;
      for (int j = 0; j < n; j++) b[j] = a[j];
      for (int j = 0; j < n; j++) a[j] = b[(j + n / i) % n] - b[j];
    }
  for (int i = 0; i < n; i++)
    if (fabs(a[i]) > 1e-8) return puts("NO"), 0;
  puts("YES");
  return 0;
}
