#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    que;
stringstream ssin;
const long long LINF = 0x7fffffffffffffffll;
const int N = 5e5 + 5, M = 1e6 + 5, mod = 1e9 + 7, INF = 0x3f3f3f3f;
int n, l;
int a[N], b[N];
inline long long read() {
  char c = getchar();
  long long x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
bool ck(int mid) {
  int mx = -INF;
  int j1 = 1, j2 = 1;
  for (int i = 1; i <= 2 * n; i++) {
    while (j1 <= 4 * n && a[i] - b[j1] > mid) j1++;
    while (j2 <= 4 * n && b[j2] - a[i] <= mid) j2++;
    mx = max(mx, j1 - i);
    if (mx > j2 - i - 1) return false;
  }
  return true;
}
int main() {
  n = read();
  l = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] += l;
    a[i + n] = a[i] + l;
  }
  for (int i = 1; i <= 3 * n; i++) {
    b[i + n] = b[i] + l;
  }
  int le = 0, ri = l / 2;
  while (le < ri) {
    int mid = le + ri >> 1;
    if (ck(mid)) {
      ri = mid;
    } else {
      le = mid + 1;
    }
  }
  cout << le << '\n';
}
