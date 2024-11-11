#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int ii = 0; ii < t; ii++) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    cin >> a[0];
    cin >> a[1];
    int b[200001] = {0};
    int kol = 0;
    int j = 0;
    int mx = 0, mxi = 0;
    for (int(i) = 2; (i) < n + 1; (i)++) {
      if (i != n)
        cin >> a[i];
      else
        a[i] = a[i - 1] + 1;
      if (a[i - 1] > a[i - 2] && a[i - 1] > a[i]) {
        kol++;
        b[i - 1] = 1;
      }
      if (i == j + k - 1) {
        if (kol > mx) {
          mx = kol;
          mxi = j;
        }
        j++;
        if (b[j] == 1) kol--;
      }
    }
    cout << mx + 1 << " " << mxi + 1 << "\n";
  }
  return 0;
}
