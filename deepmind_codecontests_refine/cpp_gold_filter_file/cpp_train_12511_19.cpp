#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, k;
  cin >> n >> k;
  if ((2 * n + 3 - sqrt((9 + 8 * (k + n)))) == 0)
    cout << 0 << endl;
  else
    cout << int(n + (3 - sqrt((9 + 8 * (k + n)))) / 2) << endl;
  cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
  return 0;
}
