#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  if (m <= n / 2)
    cout << max(1, m) << endl;
  else
    cout << n - m << endl;
  return 0;
}
