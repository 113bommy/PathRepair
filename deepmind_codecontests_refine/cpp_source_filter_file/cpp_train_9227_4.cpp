#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const int mod = 1e9 + 7;
pair<int, int> a[maxn];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x1, x2;
  cin >> n >> x1 >> x2;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    a[i].first = c, a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  int num;
  bool ok = 0;
  for (int i = n; i >= 1; i--) {
    int now = x2 / (n - i + 1);
    if (x2 % (n - i + 1) != 0) now++;
    pair<int, int> tt = {now, -inf};
    int nnn = n - (lower_bound(a + 1, a + n + 1, tt) - a) + 1;
    num = nnn;
    if (num >= (n - i + 1)) {
      num = n - i + 1;
      ok = 1;
      break;
    }
  }
  if (!ok) goto next;
  for (int i = 1; i <= n - num; i++) {
    int nn = x1 / a[i].first;
    if (x1 % a[i].first != 0) nn++;
    if (i + nn - 1 <= n - num) {
      cout << "Yes" << endl;
      cout << nn << ' ' << num << endl;
      while (nn--) cout << a[i + nn].second << ' ';
      cout << endl;
      while (num--) cout << a[n - num].second << ' ';
      return 0;
    }
  }
next:
  swap(x1, x2);
  ok = 0;
  for (int i = n; i >= 1; i--) {
    int now = x2 / (n - i + 1);
    if (x2 % (n - i + 1) == 0) now++;
    pair<int, int> tt = {now, -inf};
    int nnn = n - (lower_bound(a + 1, a + n + 1, tt) - a) + 1;
    num = nnn;
    if (num >= (n - i + 1)) {
      num = n - i + 1;
      ok = 1;
      break;
    }
  }
  if (!ok) goto endd;
  for (int i = 1; i <= n - num; i++) {
    int nn = x1 / a[i].first;
    if (x1 % a[i].first != 0) nn++;
    if (i + nn - 1 <= n - num) {
      cout << "Yes" << endl;
      cout << num << ' ' << nn << endl;
      while (num--) cout << a[n - num].second << ' ';
      cout << endl;
      while (nn--) cout << a[i + nn].second << ' ';
      return 0;
    }
  }
endd:
  cout << "No" << endl;
}
