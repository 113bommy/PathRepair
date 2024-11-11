#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, i;
  cin >> n;
  if (n <= 2)
    cout << -1;
  else {
    for (i = 0; i < n; i++) cout << i << " ";
    cout << "\n";
    for (i = 0; i < n; i++) cout << i << " ";
    cout << "\n";
    for (i = 0; i < n; i++) cout << ((2 * i) % n) << " ";
  }
}
