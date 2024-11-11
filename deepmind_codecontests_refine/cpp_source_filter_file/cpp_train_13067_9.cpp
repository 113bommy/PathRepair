#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
struct node {
  long long x, p;
  bool operator<(const node &other) const { return x < other.x; }
} sta[maxn];
long long Next[maxn];
long long skip[maxn];
long long need[maxn];
int main() {
  long long d, n, m;
  cin >> d >> n >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%I64d%I64d", &sta[i].x, &sta[i].p);
  }
  sort(sta + 1, sta + m + 1);
  sta[m + 1].x = d;
  for (int i = m; i >= 1; i--) {
    Next[i] = sta[i + 1].x - sta[i].x;
    if (sta[i].p >= sta[i + 1].p) {
      skip[i] = i + 1;
      need[i] = Next[i];
    } else {
      int k = i + 1;
      while (sta[i].p <= sta[k].p) {
        k = skip[k];
      }
      skip[i] = k;
      need[i] = sta[k].x + sta[i].x;
    }
  }
  bool ok = 1;
  long long cur = n - sta[1].x;
  if (cur < 0) ok = 0;
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    if (Next[i] > n) {
      ok = 0;
      break;
    }
    if (cur < need[i]) {
      ans += (min(n, need[i]) - cur) * sta[i].p;
      cur = min(n, need[i]);
    }
    cur -= Next[i];
  }
  if (ok) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
