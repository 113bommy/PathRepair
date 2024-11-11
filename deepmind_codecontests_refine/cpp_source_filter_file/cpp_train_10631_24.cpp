#include <bits/stdc++.h>
using namespace std;
const int mxvl = 1e1 + 12;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> vc(n);
  for (long long i = 1; i <= n; i++) cin >> vc[i];
  cout << n + 1 << "\n";
  cout << 1 << " " << n << " " << 2000000 << "\n";
  for (long long i = 1; i <= n; i++) {
    cout << 2 << " " << i << " " << vc[i] + 2000000 - i << "\n";
  }
}
