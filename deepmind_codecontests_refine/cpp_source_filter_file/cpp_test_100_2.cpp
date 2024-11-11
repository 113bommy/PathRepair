#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int64_t n;
    cin >> n;
    int64_t a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int64_t s = a[0];
    for (int i = 1; i < n; i++) {
      s = max(a[i], a[i] - a[i - 1]);
    }
    cout << s << endl;
  }
  return 0;
}
