#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, t = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') t = -1;
    c = getchar();
  }
  while (isdigit(c)) s = s * 10 + c - 48, c = getchar();
  return s * t;
}
const int N = 1e5 + 5, ma = 1e9;
struct node {
  int x;
  int is_left;
  bool operator<(const node& rhs) const {
    if (x != rhs.x)
      return x < rhs.x;
    else
      return is_left < rhs.is_left;
  }
} A[N << 1];
int n, k, point[N];
inline int Q(int dis) {
  int tot = 0;
  for (register int i = 1; i <= n; i++) {
    A[++tot].x = point[i] - dis;
    A[tot].is_left = 1;
    A[++tot].x = point[i] + dis + 1;
    A[tot].is_left = -1;
  }
  sort(A + 1, A + tot + 1);
  int sum = 0;
  for (register int i = 1; i <= tot; i++) {
    sum += A[i].is_left;
    if (sum >= k + 1) return A[i].x;
  }
  return -1;
}
int main() {
  int t = read();
  while (t--) {
    n = read(), k = read();
    for (register int i = 1; i <= n; i++) point[i] = read();
    int l = 0, r = ma, mid, ans;
    while (l < r) {
      mid = (l + r) >> 1;
      if (Q(mid) != -1)
        r = mid;
      else
        l = mid + 1;
    }
    cout << Q(l) << endl;
  }
  return 0;
}
