#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    vector<long long int> pos, neg;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] > 0)
        pos.push_back(a[i]);
      else
        neg.push_back(a[i]);
    }
    bool same = true;
    long long int mid1 = 0;
    for (int i = 0; i < n; ++i) {
      mid1 += a[i];
      if (mid1 <= 0) {
        same = false;
        break;
      }
    }
    mid1 = 0;
    if (same == true) {
      for (int i = n - 1; i >= 0; i--) {
        mid1 += a[i];
        if (mid1 <= 0) {
          same = false;
          break;
        }
      }
    }
    if (same == false) {
      cout << "NO" << '\n';
    } else
      cout << "YES" << '\n';
  }
}
