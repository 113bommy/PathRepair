#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, high = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
      if (a[i] > high) high++;
    }
    cout << high << endl;
  }
  return 0;
}
