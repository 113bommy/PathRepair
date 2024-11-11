#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline int mul(int a, int b) {
  long long x = a;
  x *= (long long)b;
  if (x >= 1000000007) x %= 1000000007;
  return x;
}
inline int add(int a, int b) {
  return (a + b) >= 1000000007 ? a + b - 1000000007 : a + b;
}
inline int sub(int a, int b) {
  return (a - b) < 0 ? 1000000007 - b + a : a - b;
}
const int MAX = INT_MAX;
const int MIN = INT_MIN;
char c[100005];
int y[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> c[i];
  int d = 0, d1 = 0;
  for (int i = 0; i < n; i++) {
    y[i] = c[i] - '0';
    if (y[i] == 1) d++;
    if (y[i] == 0) d1++;
  }
  int f = 1;
  int f2 = 0;
  for (int i = 1; i < n; i++) {
    if (y[i - 1] != y[i]) f++;
  }
  for (int i = 0; i < n - 1; i++) {
    if (y[i] == y[i + 1]) {
      f2 = 1;
      break;
    }
  }
  cout << min(f + 2, n);
  return 0;
}
