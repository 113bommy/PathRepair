#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 0 && m != 0) {
    cout << "Impossible";
    return 0;
  }
  cout << n + max(m - n, 0) << '\t' << n + m - (m == 0 ? 0 : 1);
  return 0;
}
