#include <bits/stdc++.h>
using namespace std;
int fr[5005], ans[5005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i += 1) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i += 1) {
    for (int k = 0; k < 5005; k += 1) {
      fr[k] = 0;
    }
    int mx = 0, mni = n + 1;
    for (int j = i; j < n; j += 1) {
      int el = a[j];
      fr[el] += 1;
      if (fr[el] > mx) {
        mx = fr[el];
        mni = el;
      } else if (fr[el] == mx) {
        mni = min(mni, el);
      }
      ans[mni] += 1;
    }
  }
  for (int i = 1; i <= n; i += 1) {
    cout << ans[i] << ' ';
  }
  return 0;
}
