#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[200005];
int idx[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    ll s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    if ((s * 2) % n != 0) {
      cout << 0 << '\n';
      continue;
    }
    sort(a, a + n);
    idx[0] = 0;
    int pos = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[i - 1]) {
        idx[pos] = i;
        pos++;
      }
    }
    idx[pos] = n;
    int left = 0;
    int right = pos - 1;
    ll cnt = 0;
    ll ps = (s * 2) / n;
    while (left < right) {
      ll cs = a[idx[left]] + a[idx[right]];
      if (cs == ps) {
        cnt += (idx[left + 1] - idx[left]) * (idx[right + 1] - idx[right]);
        left += 1;
        right -= 1;
      } else if (cs > ps) {
        right -= 1;
      } else {
        left += 1;
      }
    }
    if (left == right && a[idx[left]] * 2 == ps) {
      ll diff = idx[left + 1] - idx[left];
      cnt += diff * (diff - 1) / 2;
    }
    cout << cnt << '\n';
  }
}
