#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
const int MAXN = 10 * 1000;
int n, sum_x;
pair<int, pair<int, int> > edg[MAXN];
int x[MAXN], color[MAXN], num[MAXN], sum[MAXN];
bool check(int w) {
  for (int i = 0; i < n; ++i) {
    color[i] = i;
  }
  for (int i = 0; i < n - 1 && edg[i].first < w; ++i) {
    int v1 = edg[i].second.first;
    int v2 = edg[i].second.second;
    if (color[v1] != color[v2]) {
      int c1 = color[v1];
      for (int i = 0; i < n; ++i) {
        if (color[i] == c1) {
          color[i] = color[v2];
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    num[i] = 0;
    sum[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    num[color[i]]++;
    sum[color[i]] += x[i];
  }
  for (int i = 0; i < n; ++i) {
    if (num[i] > sum_x - sum[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> n;
  int max_w = 0;
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d %d %d", &edg[i].second.first, &edg[i].second.second,
          &edg[i].first);
    edg[i].second.first--;
    edg[i].second.second--;
    max_w = max(max_w, edg[i].first);
  }
  sum_x = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
    sum_x += x[i];
  }
  sort(edg, edg + n - 1);
  int l = 0;
  int r = max_w;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l << endl;
  return 0;
}
