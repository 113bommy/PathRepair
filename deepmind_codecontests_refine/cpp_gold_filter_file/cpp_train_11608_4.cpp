#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 100005;
int cnt[maxn * 10];
int l[maxn * 10], r[maxn * 10];
int main() {
  int n;
  scanf("%d", &n);
  int a;
  memset(l, -1, sizeof(l));
  memset(r, -1, sizeof(r));
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    cnt[a]++;
    if (l[a] == -1)
      l[a] = r[a] = i;
    else
      r[a] = i;
  }
  vector<pair<int, int> > v;
  int cmp = 0;
  int p = 0, q = 0;
  for (int i = 1; i <= 1000000; i++) {
    if (cnt[i]) {
      if (cmp < cnt[i]) {
        cmp = cnt[i];
        p = l[i], q = r[i];
      } else if (cmp == cnt[i] && r[i] - l[i] <= q - p) {
        p = l[i], q = r[i];
      }
    }
  }
  cout << p + 1 << ' ' << q + 1 << endl;
  return 0;
}
