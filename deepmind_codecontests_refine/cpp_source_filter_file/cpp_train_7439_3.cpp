#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> p(n);
  for (int i = 1, k = 1; i < n; i++) {
    p[i] = p[i - 1];
    if (k && a[i - 1] > a[i] || !k && a[i - 1] < a[i]) {
      p[i] = i - 1;
      k = !k;
    }
  }
  vector<int> ans(n);
  for (int i = 1; i < n; i++) {
    int j = p[i];
    ans[i] = max((j > 0 ? ans[j - 1] : 0) + abs(a[i] - a[j]),
                 ans[j] + (j < i ? abs(a[i] - a[j + 1]) : 0));
  }
  cout << ans[n - 1] << endl;
  return 0;
}
