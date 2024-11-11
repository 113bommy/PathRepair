#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    if (m % 2 == 1) m--;
    if (m / 2 < n) {
      cout << -1 << " " << -1 << '\n';
    } else
      cout << m / 2 << " " << m << '\n';
  }
}
