#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i_thWalrus = 1;
  cin >> n >> m;
  while (m >= i_thWalrus) {
    m -= i_thWalrus;
    i_thWalrus--;
    if (i_thWalrus == 0) i_thWalrus = n;
  }
  cout << m;
}
