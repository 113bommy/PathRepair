#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> m(n), t(n), maxi(n), idx(n);
  long long msum = 0, suma = 0;
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
    msum += m[i] + 1;
    if (i == 0 || m[i] + 1 > maxi[i - 1]) {
      maxi[i] = m[i] + 1;
      idx[i] = i;
    } else if (m[i] + 1 == maxi[i - 1]) {
      maxi[i] = maxi[i - 1];
      idx[i] = i;
    } else {
      maxi[i] = maxi[i - 1];
      idx[i] = idx[i - 1];
    }
  }
  int cur = maxi[n - 1];
  for (int i = n - 1; i >= 0; --i) {
    suma += cur;
    if (i > 0 && cur >= maxi[i - 1]) {
      --cur;
    }
  }
  cout << suma - msum << endl;
  return 0;
}
