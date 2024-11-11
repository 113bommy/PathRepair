#include <bits/stdc++.h>
using namespace std;
const int MaxN = 200005;
const double eps = 1e-9;
const double DINF = 1e100;
const int INF = 1000000006;
const long long LINF = 1000000000000000005ll;
int n;
int que[MaxN];
long long a[MaxN], b[MaxN];
long long f[MaxN];
bool check(int i, int j, int k) {
  long double x1 = b[i] - b[j];
  long double y1 = f[i] - f[j];
  long double x2 = b[k] - b[j];
  long double y2 = f[k] - b[j];
  return x1 * y2 - x2 * y1 < -eps;
}
long long calc(int i, long long k) { return f[i] + k * b[i]; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%I64d", a + i);
  for (int i = 1; i <= n; ++i) scanf("%I64d", b + i);
  f[1] = 0;
  int front, tail;
  que[front = tail = 0] = 1;
  for (int i = 2; i <= n; ++i) {
    while (front < tail) {
      long long f1 = calc(que[front], a[i]);
      long long f2 = calc(que[front + 1], a[i]);
      if (f1 >= f2)
        ++front;
      else
        break;
    }
    f[i] = calc(que[front], a[i]);
    while (front < tail && !check(que[tail - 1], que[tail], i)) --tail;
    que[++tail] = i;
  }
  cout << f[n] << endl;
  return 0;
}
