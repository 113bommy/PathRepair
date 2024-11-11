#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 10;
int n, a[MX], out[MX], mn[MX];
int bs(int L, int R, int val) {
  if (R - L == 1) return L;
  int mid = (R + L) / 2;
  if (val < a[mid])
    return bs(L, mid, val);
  else
    return bs(mid, R, val);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  mn[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) mn[i] = min(mn[i + 1], a[i]);
  for (int i = n - 1; i >= 0; --i) {
    if (mn[i] == a[i])
      out[i] = -1;
    else {
      int x = bs(i + 1, n, a[i]);
      out[i] = x - i - 1;
    }
  }
  for (int i = 0; i < n; ++i) cout << out[i] << " ";
}
