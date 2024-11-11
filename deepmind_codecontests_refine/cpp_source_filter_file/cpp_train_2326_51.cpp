#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, ct = 0, x;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x;
    ct += n - x;
  }
  ct -= x;
  cout << ct << "\n";
}
