#include <bits/stdc++.h>
using namespace std;
struct str {
  long long l, r;
} st[6666666];
bool cmp(str a, str b) {
  if (a.l != b.l) {
    return a.l < b.l;
  } else {
    return a.r < b.r;
  }
}
signed main() {
  long long n;
  cin >> n;
  if (n <= 2) {
    cout << "YES";
    return 0;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> st[i].l >> st[i].r;
  }
  sort(st + 1, st + 1 + n, cmp);
  long long f1 = st[1].r;
  long long f2 = st[2].r;
  long long F = 1;
  for (long long i = 3; i <= n; i++) {
    if (f1 < st[i].l) {
      f1 = st[i].r;
    } else if (f2 < st[i].l) {
      f2 = st[i].r;
    } else {
      F = 0;
      break;
    }
  }
  if (F) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
