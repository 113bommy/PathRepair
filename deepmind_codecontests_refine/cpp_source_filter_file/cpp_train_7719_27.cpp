#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (m == 1 || m == 0) return cout << 0, 0;
  cout << min(m, n - m);
}
