#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 1e5 + 55;
const long long int inf = 1e18;
const long long int lg = 20;
const long long int modn = 1e9 + 7;
long long int T, len, num, sum, x, fir, sec;
long long int all[maxn];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> fir >> sec;
    if ((sec + 1) / 2 >= fir)
      cout << (sec - 1) / 2 << endl;
    else
      cout << sec % fir << endl;
  }
  return 0;
}
