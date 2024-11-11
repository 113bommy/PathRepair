#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
long long b[maxn];
struct King {
  int id, w;
  long long t;
} a[maxn];
bool cmp(King A, King B) {
  if (A.w == B.w)
    return A.t > B.t;
  else
    return A.w < B.w;
}
int n, k;
int main() {
  while (cin >> n >> k) {
    memset(b, -1, sizeof(-1));
    memset(a, -1, sizeof(-1));
    int tot = 0;
    for (int i = 0; i < n; i++) {
      a[i].id = i;
      cin >> a[i].w;
    }
    for (int i = 0; i < n; i++) cin >> a[i].t;
    sort(a, a + n, cmp);
    for (int i = 1; i < n; i++) {
      if (a[i].w == a[i - 1].w) {
        b[tot++] = a[i].t;
      }
    }
    sort(b, b + tot);
    long long ans = 0;
    if (tot == 0)
      ans = 0;
    else {
      int tmp = k - tot;
      for (int i = 0; i < tmp; i++) ans += b[i];
    }
    cout << ans << endl;
  }
  return 0;
}
