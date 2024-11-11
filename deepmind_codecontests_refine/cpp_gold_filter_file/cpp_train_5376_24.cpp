#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n > 30)
    cout << m << '\n';
  else
    cout << m % (1 << n) << '\n';
  return 0;
}
