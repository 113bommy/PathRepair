#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, neg = 0, pos = 0;
    cin >> n;
    int ar[n + 2];
    for (int i = 1; i <= n; i++) {
      cin >> ar[i];
      if (ar[i] < 0)
        neg += abs(ar[i]);
      else if (ar[i] > 0)
        pos += ar[i];
    }
    sort(ar + 1, ar + n + 1);
    if (neg > pos) {
      cout << "YES" << endl;
      for (int i = 1; i <= n; i++) cout << ar[i] << " ";
      cout << endl;
    } else if (pos > neg) {
      cout << "YES" << endl;
      for (int i = n; i >= 1; i--) cout << ar[i] << " ";
      cout << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
