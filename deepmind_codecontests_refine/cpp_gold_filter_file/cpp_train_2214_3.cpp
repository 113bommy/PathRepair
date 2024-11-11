#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(12);
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> lc;
    long long an = 0;
    for (int i = 0; i < n; i++) {
      unordered_map<int, int> rc;
      for (int j = n - 1; j > i; j--) {
        an += lc[a[j]] * rc[a[i]];
        rc[a[j]]++;
      }
      lc[a[i]]++;
    }
    cout << an << "\n";
  }
  return 0;
}
