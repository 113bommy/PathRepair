#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, m{}, k{}, i{};
  cin >> n;
  vector<int> a(n);
  for (int j = 0; j < n; ++j) {
    cin >> a[j];
    k += a[j] == 0 ? 1 : -1;
    if (k > m) m = k, i = j;
    if (k < 0) k = 0;
  }
  k = m;
  for (int j = i; k != 0; k -= a[j] == 0 ? 1 : -1, --j) a[j] = !a[j];
  cout << (m == 0 ? n - 1 : count(a.begin(), a.end(), 1));
}
