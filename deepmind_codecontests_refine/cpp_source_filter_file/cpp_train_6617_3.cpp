#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double PI = acos(-1);
const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;
inline int readint() {
  int sum = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  if (f) return -sum;
  return sum;
}
inline long long readLL() {
  long long sum = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  if (f) return -sum;
  return sum;
}
long long a[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, n1, n2;
  cin >> n >> n1 >> n2;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  cout << setprecision(20)
       << (a[n] - a[n - min(n1, n2)]) * 1.0 / min(n1, n2) +
              (a[n - min(n1, n2)] - a[n - n1 - n2]) * 1.0 / max(n1, n2)
       << endl;
  return 0;
}
