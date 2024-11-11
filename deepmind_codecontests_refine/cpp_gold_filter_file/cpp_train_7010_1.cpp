#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n == 0 && m > 0) {
    cout << "Impossible\n";
    return 0;
  }
  int j = m - min(n, m);
  if (m != 0)
    cout << n + j << " " << n + m - 1;
  else
    cout << n + j << " " << n + m;
  return 0;
}
