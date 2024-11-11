#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int u;
  int par = 0, ne = 0;
  for (int i = 0; i < n; i++) {
    cin >> u;
    if (u % 2 == 0)
      par++;
    else
      ne++;
  }
  if (par >= ne)
    cout << ne;
  else
    cout << par + (ne - par) / 2;
  return 0;
}
