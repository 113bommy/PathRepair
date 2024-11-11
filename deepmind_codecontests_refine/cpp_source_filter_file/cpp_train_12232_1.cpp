#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, t[N];
pair<int, int> a[N], b[N];
pair<int, int> st[N];
int top = 0;
pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
long long operator*(const pair<int, int> &a, const pair<int, int> &b) {
  return 1LL * a.first * b.second - 1LL * a.second * b.first;
}
int main() {
  scanf("%d%d", &n, &m);
  {
    int first, second;
    scanf("%d%d", &first, &second);
  }
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  for (int i = 1; i <= m; i++) scanf("%d%d", &b[i].first, &b[i].second);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= m; i++) t[i] = b[i].second;
  int s = max_element(t + 1, t + m + 1) - t;
  for (int i = s; i <= m; i++) {
    while (top >= 2 && (st[top] - st[top - 1]) * (b[i] - st[top]) >= 0) top--;
    st[++top] = b[i];
  }
  st[0] = make_pair(0, st[1].second);
  int j = 1;
  for (int i = 1; i <= n; i++) {
    while (j <= top && st[j].first < a[i].first) j++;
    if (j > top) {
      printf("Max\n");
      return 0;
    }
    pair<int, int> t = a[i] - st[j - 1], t1 = st[j] - st[j - 1];
    if (t * t1 <= 0) {
      printf("Max\n");
      return 0;
    }
  }
  printf("Min\n");
  return 0;
}
