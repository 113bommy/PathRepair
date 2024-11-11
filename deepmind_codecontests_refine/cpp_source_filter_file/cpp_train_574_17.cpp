#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, k, w, t, cur, r, a, b;
int v[200005], p[200005], q[200005], R[200005], Merge[200005];
long long ans[100005];
struct node {
  int x, y;
  bool operator<(node const& T) const { return T.y > y; }
} A[100005];
vector<int> s[200005];
vector<int>::iterator it;
int bs(int val) {
  int mid, low = -1, high = w;
  while (high - low > 1) {
    mid = (high + low) / 2;
    if (v[mid] < val)
      low = mid;
    else
      high = mid;
  }
  return high;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (0); i < (n); i++) scanf("%d %d", &A[i].x, &A[i].y);
  sort(A, A + n);
  for (int i = (0); i < (n); i++) {
    v[w++] = A[i].x - k + 1;
    v[w++] = A[i].x + 1;
  }
  sort(v, v + w);
  x = 1;
  for (int i = (1); i < (w); i++)
    if (v[i] != v[x - 1]) v[x++] = v[i];
  w = x;
  for (int i = (0); i < (n); i++) {
    x = bs(A[i].x - k + 1);
    y = bs(A[i].x + 1);
    for (int j = (x); j < (y); j++) s[j].push_back(A[i].y);
  }
  for (int i = (0); i < (n - 1); i++) {
    m = 0;
    for (it = s[i].begin(); it != s[i].end(); it++) {
      R[m] = *it;
      p[m] = *it - k + 1;
      q[m++] = *it + 1;
    }
    x = y = 0;
    r = m;
    for (int j = (0); j < (2 * m); j++) {
      if (x < m)
        a = p[x];
      else
        a = 2000000000;
      if (y < m)
        b = q[y];
      else
        b = 2000000000;
      if (a < b) {
        Merge[j] = a;
        x++;
      } else {
        Merge[j] = b;
        y++;
      }
    }
    m = 2 * m;
    for (int j = (0); j < (m); j++) p[j] = Merge[j];
    t = 1;
    for (int j = (1); j < (m); j++)
      if (p[j] != p[t - 1]) p[t++] = p[j];
    m = t;
    x = 0;
    y = 0;
    cur = 0;
    for (int j = (0); j < (m); j++) {
      while (R[x] >= p[j] && R[x] < p[j] + k && x < r) {
        x++;
        cur++;
      }
      while (R[y] < p[j] && y < r) {
        y++;
        cur--;
      }
      ans[cur] += 1ll * (p[j + 1] - p[j]) * (v[i + 1] - v[i]);
    }
  }
  for (int i = (1); i <= (n); i++) printf("%I64d ", ans[i]);
  return 0;
}
