#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    unordered_set<int> s;
    int l = 0, ans = k + 1;
    for (int i = 0; i < n - d + 1; i++) {
      for (int j = i; j < i + d; j++) {
        if (s.find(a[j]) == s.end()) {
          s.insert(a[j]);
          l++;
        }
        if (((j + 1) - i) % d == 0) {
          ans = min(ans, l);
          s.clear();
          l = 0;
        }
      }
    }
    s.clear();
    cout << ans << "\n";
  }
  return 0;
}
