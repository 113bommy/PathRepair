#include <bits/stdc++.h>
using namespace std;
using li = long int;
using lli = long long int;
void counts(int a[], int n) {
  set<int> s;
  int m = INT_MIN;
  for (int i = n - 1; i >= 0; i--) {
    s.insert(a[i]);
    auto it = s.lower_bound(a[i]);
    int ans = distance(s.begin(), it);
    m = max(m, ans);
  }
  cout << m << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, c = -1, p = 0, q = -1, d = 0, ans = 1;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    for (long long i = 0; i < n; i++) {
      if (a[i] < 0) {
        d++;
        q = i;
      }
    }
    if (n - d == 0) {
      ans = a[q] * a[q - 1] * a[q - 2] * a[q - 3] * a[q - 4];
    } else if (n - d < 3 && n - d > 0) {
      ans = a[0] * a[1] * a[2] * a[3] * a[n - 1];
    } else if (n - d == 3) {
      ans = max(a[0] * a[1] * a[2] * a[3] * a[n - 1],
                a[0] * a[1] * a[n - 3] * a[n - 2] * a[n - 1]);
    } else if (n - d > 3) {
      if (n - d < 5)
        ans = max(a[0] * a[1] * a[2] * a[3] * a[n - 1],
                  a[0] * a[1] * a[n - 3] * a[n - 2] * a[n - 1]);
      else
        ans = max(a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5],
                  max(a[0] * a[1] * a[2] * a[3] * a[n - 1],
                      a[0] * a[1] * a[n - 3] * a[n - 2] * a[n - 1]));
    } else if (n - d == 0)
      ans = a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5];
    cout << ans << endl;
  }
}
