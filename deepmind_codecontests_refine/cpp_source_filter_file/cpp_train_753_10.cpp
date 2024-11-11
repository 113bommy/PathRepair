#include <bits/stdc++.h>
using namespace std;
const int Max = 3e5 + 10;
long long A[Max];
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int k;
    cin >> k;
    long long mn = 1000000000000, mx = -100000000000;
    for (int i = 0; i < n; i++) {
      long long a;
      cin >> a;
      A[i] = a;
      mn = min(mn, a);
      mx = max(mx, a);
    }
    for (int i = 0; i < n; i++) {
      if (k % 2)
        cout << mx - A[i] << " ";
      else
        cout << A[i] - mn << " ";
    }
    cout << '\n';
  }
}
