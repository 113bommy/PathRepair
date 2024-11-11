#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    cout << (n * m) / 2 + 1 << endl;
  }
  return 0;
}
