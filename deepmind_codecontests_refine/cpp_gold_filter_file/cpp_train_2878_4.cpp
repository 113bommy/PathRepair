#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int f = 0, x = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    f = (f << 1) + (f << 3) + ch - '0';
    ch = getchar();
  }
  return f * x;
}
struct data {
  long double x, y;
} a[100005], b[100005];
const long double eps = 1e-16;
bool cmp(const data &x, const data &y) {
  if (abs(x.x - y.x) > eps) return x.x < y.x;
  return x.y > y.y;
}
int n;
long long ans;
long double line(int x) { return sqrt((a[x].x) * a[x].x + a[x].y * a[x].y); }
void mergesort(int l, int mid, int r) {
  int i = 0, j = l, k = mid + 1;
  while (j <= mid && k <= r) {
    if (a[j].y > a[k].y || abs(a[j].y - a[k].y) < eps) {
      b[i++] = a[k++];
      ans += mid - j + 1;
    } else {
      b[i++] = a[j++];
    }
  }
  while (j <= mid) b[i++] = a[j++];
  while (k <= r) b[i++] = a[k++];
  for (j = 0; j < i; j++) a[l + j] = b[j];
}
void merge(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  merge(l, mid);
  merge(mid + 1, r);
  mergesort(l, mid, r);
}
int main() {
  n = read();
  long double w = read();
  if (w != 0) {
    for (int i = 1; i <= n; i++) {
      long double x = read(), y = read();
      long double tempx = 1.0 / x, tempy = -y / x;
      tempy /= w;
      a[i].x = tempx * 100.0, a[i].y = tempy * 100.0;
    }
    for (int i = 1; i <= n; i++) {
      long double sin = sqrt(2.0) / 2.0, cos = sqrt(2.0) / 2.0;
      long double tempy = cos * a[i].y - sin * a[i].x,
                  tempx = sin * a[i].x + cos * a[i].y;
      a[i].x = tempx, a[i].y = tempy;
    }
  } else {
    for (int i = 1; i <= n; i++) {
      long double x = read(), y = read();
      a[i].x = y / x;
    }
    int last = 1;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 2; i <= n; i++) {
      if (a[i].x != a[i - 1].x) {
        ans += 1LL * (i - last) * (i - last - 1) / 2;
        last = i;
      }
    }
    ans += 1LL * (n - last + 1) * (n - last) / 2;
    cout << ans;
    return 0;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
  }
  merge(1, n);
  cout << ans;
}
