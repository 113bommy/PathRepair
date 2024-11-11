#include <bits/stdc++.h>
using namespace std;
long long a, b, mod;
int main() {
  ios::sync_with_stdio(false);
  cin >> a >> b >> mod;
  if (a == 0 || mod == 1 || b >= mod - 1) {
    cout << 2 << endl;
  } else {
    long long ans = -1;
    long long r = 1000000000 % mod;
    for (long long i = 1; i <= mod; ++i) {
      long long t = (i * r) % mod;
      if (t != 0 && mod - t > b) {
        ans = i;
        break;
      }
    }
    if (ans == -1)
      cout << 2 << endl;
    else {
      cout << 1 << ' ';
      vector<int> res;
      while (ans) {
        res.push_back(ans % 10);
        ans /= 10;
      }
      for (int j = 0; j < 9 - res.size(); ++j) cout << 0;
      int L = (int)(res.size()) - 1;
      for (int j = L; j >= 0; --j) cout << res[j];
      cout << endl;
    }
  }
  return 0;
}
