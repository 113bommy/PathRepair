#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, i, j;
    cin >> n;
    long long a[n + 5], b[n + 5];
    for (i = 0; i < n; i++) cin >> a[i];
    vector<long long> v;
    for (i = 0; i < n; i++) cin >> b[i];
    for (i = 0; i < n; i++) {
      if (b[i] == 0) v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    j = 0;
    for (i = 0; i < n; i++) {
      if (b[i] == 0) {
        a[i] = v[j];
        j++;
      }
    }
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
