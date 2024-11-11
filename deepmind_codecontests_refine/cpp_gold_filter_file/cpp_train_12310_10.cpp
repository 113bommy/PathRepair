#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      a.push_back(p);
    }
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      b.push_back(p);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0, r = n - 1;
    while (k > 0 && l < n && r >= 0) {
      if (a[l] < b[r]) {
        swap(a[l], b[r]);
        r--;
        l++;
        k--;
      } else {
        break;
      }
    }
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    cout << sum << "\n";
  }
}
