#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, i, a, newPage, currentPage, ans;
  cin >> n >> m;
  currentPage = 0;
  for (i = n; i <= n; i++) {
    cin >> a;
    newPage = a + currentPage;
    ans = newPage / m;
    currentPage = newPage % m;
    cout << ans;
    if (n != i) cout << " ";
  }
  cout << endl;
  return 0;
}
