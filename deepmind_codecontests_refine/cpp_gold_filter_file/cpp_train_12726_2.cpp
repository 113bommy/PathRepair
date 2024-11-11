#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")
using namespace std;
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  iostream::sync_with_stdio(0);
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long q;
  cin >> q;
  while (q--) {
    long long n, m;
    cin >> n >> m;
    if (n == 1) {
      cout << "0" << '\n';
      continue;
    }
    if (n == 2) {
      cout << m << '\n';
      continue;
    }
    if (n > 2) {
      cout << 2 * m << '\n';
      continue;
    }
  }
}
