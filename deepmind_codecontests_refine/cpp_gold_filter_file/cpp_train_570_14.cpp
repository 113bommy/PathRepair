#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 2000000000;
const ll si = 100005;
int n, ar[500005], ans[500005], op = 0;
void pros(int i, int j) {
  int si = j - i + 1;
  if (si == 1 || si == 2) {
    ans[i] = ar[i];
    ans[j] = ar[j];
    return;
  }
  if (si % 2 == 0) {
    int fo = ar[i], r, lim;
    for (r = i, lim = i + (si / 2); r < lim; r++) ans[r] = fo;
    fo ^= 1;
    for (r = lim; r <= j; r++) ans[r] = fo;
    op = max(op, (si - 1) / 2);
  } else {
    int def = ar[i], top = (si - 1) / 2;
    for (int r = i; r <= j; r++) ans[r] = def;
    op = max(top, op);
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ar[i];
  int s = 0;
  for (int i = 1; i < n; i++) {
    if (ar[i] == ar[i - 1]) {
      pros(s, i - 1);
      s = i;
    }
  }
  pros(s, n - 1);
  cout << op << "\n";
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
