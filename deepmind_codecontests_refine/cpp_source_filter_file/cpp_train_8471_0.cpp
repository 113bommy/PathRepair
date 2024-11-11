#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
int n, m;
int a[1024];
int b[1024];
long long mult[1024];
long long divi[1024];
void dec(int x) {
  for (int i = 2; i <= x; i++) {
    while (x % i == 0) {
      mult[i]--;
      x = x / i;
    }
    if (x == 1) break;
  }
}
void inc(int x) {
  for (int i = 2; i <= x; i++) {
    while (x % i == 0) {
      mult[i]++;
      x = x / i;
    }
    if (x == 1) break;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  if (n == m) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + m + 1);
  a[0] = 0;
  a[m + 1] = n + 1;
  for (int i = 1; i <= m + 1; i++) {
    b[i] = a[i] - a[i - 1] - 1;
  }
  memset(mult, 0, sizeof(mult));
  memset(divi, 0, sizeof(divi));
  for (int i = 2; i <= m; i++) {
    if (b[i] != 0) {
      mult[2] += b[i] - 1;
    }
  }
  for (int i = 1; i <= n - m; i++) {
    inc(i);
  }
  for (int i = 1; i <= m + 1; i++) {
    if (b[i] != 0) {
      for (int j = 1; j <= b[i]; j++) {
        dec(j);
      }
    }
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    if (mult[i] != 0) {
      for (int j = 1; j <= mult[i]; j++) {
        ans *= i;
        ans = ans % 1000000007;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
