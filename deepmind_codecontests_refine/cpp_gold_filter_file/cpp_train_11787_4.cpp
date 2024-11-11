#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), cnt(2e+5 + 2);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int mn = 0, mx = 0, i = 0;
  while (i < cnt.size()) {
    if (cnt[i] == 0)
      i++;
    else
      mn++, i += 3;
  }
  for (int i = 1; i < cnt.size() - 1; i++) {
    int k = cnt[i];
    cnt[i] = 0;
    if (k == 1) {
      if (cnt[i - 1] == 0)
        cnt[i - 1] = 1;
      else
        cnt[i] = 1;
    }
    if (k == 2) {
      if (cnt[i - 1] == 0)
        cnt[i - 1] = 1;
      else
        cnt[i + 1]++;
      cnt[i] = 1;
    }
    if (k >= 3) {
      cnt[i - 1] = 1;
      cnt[i] = 1;
      cnt[i + 1]++;
    }
  }
  int ans = 0;
  for (int i : cnt) {
    if (i) ans++;
  }
  cout << mn << ' ' << ans;
}
