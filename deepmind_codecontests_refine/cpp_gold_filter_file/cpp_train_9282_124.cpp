#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using namespace std;
const int maxn = 3e4 + 100;
const int MAX = 1e2 + 10;
int n, m, k;
int main() {
  cin >> n >> m >> k;
  if (min(m, k) >= n)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
