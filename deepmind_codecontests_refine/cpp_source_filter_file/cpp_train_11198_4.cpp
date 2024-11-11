#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, l, m, a, miN, i, k;
  cin >> n >> a;
  miN = n;
  for (i = 0; i < a; i++) {
    cin >> l >> m;
    miN = min(miN, m - l + 1);
  }
  cout << miN + 1 << endl;
  for (i = 0; i < n; i++) {
    cout << i % miN << " ";
  }
}
