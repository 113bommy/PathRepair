#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
};
int n;
int A[100009];
vector<point> X;
point B[100009];
inline bool cmpx(point a, point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
inline bool cmpy(point a, point b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
long long dist(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
long long dvd(int a, int b) {
  long long ret = INT_MAX;
  if (b - a + 1 < 4) {
    for (int i = a; i <= b; i++)
      for (int j = i + 1; j <= b; j++)
        ret = (ret < dist(X[i], X[j]) ? ret : dist(X[i], X[j]));
    return ret;
  }
  int mid = (b - a + 1) / 2;
  long long x = dvd(a, a + mid);
  long long y = dvd(a + mid + 1, b);
  ret = (ret < (x < y ? x : y) ? ret : (x < y ? x : y));
  long long linex = X[mid].x;
  int sz = 0;
  for (int i = a; i <= b; i++)
    if (abs(linex - X[i].x) <= ret) B[sz++] = X[i];
  sort(B, B + sz, cmpy);
  for (int i = 0; i < sz; i++)
    for (int j = i + 1; j < (sz < i + 8 ? sz : i + 8); j++)
      ret = (ret < dist(B[i], B[j]) ? ret : dist(B[i], B[j]));
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", A + i);
  for (int i = 1; i < n; i++) A[i] += A[i - 1];
  X.resize(n);
  for (int i = 0; i < n; i++) X[i].x = i, X[i].y = A[i];
  sort((X).begin(), (X).end(), cmpx);
  printf("%lld\n", dvd(0, n - 1));
}
