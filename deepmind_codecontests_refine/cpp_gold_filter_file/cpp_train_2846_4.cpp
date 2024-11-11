#include <bits/stdc++.h>
using namespace std;
int n, m, c;
vector<int> a, b;
vector<pair<int, int> > arr;
void solve() {
  for (int i = 0; i < n; ++i) {
    int f = arr[i].first, l = arr[i].second;
    a[i] += b[l];
    if (f) {
      a[i] -= b[f - 1];
    }
  }
}
int main(int argc, char *argv[]) {
  scanf("%d%d%d", &n, &m, &c);
  a.resize(n);
  b.resize(m);
  arr.resize(n);
  for (int i = 0; i < n - m + 1; ++i) {
    arr[i].first = 0;
    arr[n - i - 1].second = m - 1;
  }
  for (int i = n - m + 1; i < n; ++i) {
    arr[i].first = i - n + m;
    arr[n - i - 1].second = m - (i - (n - m + 1) + 2);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
    if (i) {
      b[i] += b[i - 1];
    }
  }
  solve();
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i] % c);
  }
  return 0;
}
