#include <bits/stdc++.h>
using namespace std;
int a[100000];
int cnt[50001];
int main() {
  int n;
  cin >> n;
  int minv = 1e9;
  int maxv = 1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    minv = min(minv, a[i]);
    maxv = max(maxv, a[i]);
  }
  if (2 * (maxv - minv) > 1e5) {
    cout << "NO" << endl;
  } else {
    for (int i = 0; i < n; ++i) {
      ++cnt[a[i] - minv];
    }
    bool works = true;
    int lim = maxv - minv;
    ++cnt[0];
    ++cnt[lim];
    for (int i = 0; i <= lim && works; ++i) {
      cnt[i] -= 2;
      if (cnt[i] < 0) {
        works = false;
      }
    }
    for (int i = 0; i <= lim && works; ++i) {
      if (cnt[i] > cnt[i + 1]) {
        works = false;
      } else {
        cnt[i + 1] -= cnt[i];
      }
    }
    cout << (works ? "YES" : "NO") << endl;
  }
  return 0;
}
