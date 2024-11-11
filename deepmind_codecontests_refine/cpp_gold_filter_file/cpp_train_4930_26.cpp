#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
int a[N];
int l[N], r[N];
long long w[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  a[0] = a[n + 1] = 0;
  l[0] = 0, r[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) {
    int x = i;
    while (a[x - 1] >= a[i]) {
      x = l[x - 1];
    }
    l[i] = x;
  }
  for (int i = n; i >= 1; i--) {
    int x = i;
    while (a[x + 1] >= a[i]) {
      x = r[x + 1];
    }
    r[i] = x;
  }
  set<pair<int, int> > s;
  memset(w, 0, sizeof(w));
  for (int i = 1; i <= n; i++) {
    if (s.find(make_pair(l[i], r[i])) == s.end()) {
      s.insert(make_pair(l[i], r[i]));
      w[r[i] - l[i] + 1] += a[i] - max(a[l[i] - 1], a[r[i] + 1]);
    }
  }
  for (int j = 0; j < 2; j++) {
    for (int i = n; i >= 1; i--) w[i] += w[i + 1];
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int k;
    scanf("%d", &k);
    printf("%.9f\n", w[k] * 1.0 / (n - k + 1));
  }
  return 0;
}
