#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p;
  cin >> n >> p;
  map<int, int> cnt;
  vector<int> ar(n);
  for (auto &i : ar) cin >> i, cnt[i]++;
  sort(ar.begin(), ar.end());
  int lo = 0, hi = ar.back();
  while (lo < hi - 1) {
    int mid = lo + (hi - lo) / 2, tmp = mid;
    for (int i = 0; i < n; i++) {
      if (ar[i] <= tmp)
        tmp++;
      else
        break;
    }
    if (tmp >= ar.back())
      hi = mid;
    else
      lo = mid;
  }
  int mi = hi, tmp = p - 1, ok = 1;
  int pos = upper_bound(ar.begin(), ar.end(), mi) - ar.begin();
  for (int i = pos; i < n; i++) {
    int num = i + cnt[ar[i]], need = ar[i] - mi;
    if (num - need >= p) {
      ok = 0;
      break;
    }
    while (i + 1 < n and ar[i + 1] == ar[i]) i++;
  }
  while (tmp >= 0 and ar[tmp] == ar[p - 1]) tmp--;
  if (!ok or tmp < 0 or mi >= ar[tmp + 1])
    cout << 0 << '\n' << '\n';
  else {
    lo = mi, hi = ar[tmp + 1];
    while (lo < hi - 1) {
      int mid = lo + (hi - lo) / 2, ok = 1;
      pos = upper_bound(ar.begin(), ar.end(), mid) - ar.begin();
      for (int i = pos; i < n; i++) {
        int num = i + cnt[ar[i]], need = ar[i] - mid;
        if (num - need >= p) {
          ok = 0;
          break;
        }
        while (i + 1 < n and ar[i + 1] == ar[i]) i++;
      }
      if (ok)
        lo = mid;
      else
        hi = mid;
    }
    int ans = lo - mi + 1;
    cout << ans << '\n';
    for (int i = mi; i <= lo; i++) cout << i << ' ';
    cout << '\n';
  }
}
