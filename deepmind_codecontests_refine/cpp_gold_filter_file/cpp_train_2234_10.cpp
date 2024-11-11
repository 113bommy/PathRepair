#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  if (n < m)
    cout << -1;
  else
    cout << ceil((n / 2 + n % 2) / double(m)) * m;
  return 0;
}
