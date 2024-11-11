#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n, m, mn, mx, cnt = 2, tem;
bool b = true;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> mn >> mx;
  for (int i = 0; i < m; i++) {
    cin >> tem;
    if (tem > mn && tem < mx)
      cnt++;
    else if (tem < mn || tem > mx)
      b = false;
  }
  cout << ((cnt == n && b) ? "Correct" : "Incorrect");
  return 0;
}
