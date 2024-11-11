#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.);
const long long mod = 1000000007;
inline void prep() {
  cin.tie(0);
  cin.sync_with_stdio(0);
};
int main() {
  prep();
  string n;
  cin >> n;
  int upto = pow(2, n.size());
  int minn = 10000000;
  for (int i = 1; i < upto; i++) {
    bitset<9> bs(i);
    bool good = true;
    for (int j = 0; j < n.size(); j++) {
      if (bs[j] == 1) {
        if (n[j] == '0') {
          good = false;
        }
        break;
      }
    }
    if (!good) {
      continue;
    }
    int actualnum = 0;
    int tens = pow(10, bs.count() - 1);
    for (int j = 0; j < n.size(); j++) {
      if (bs[j] == 1) {
        actualnum += (n[j] - '0') * tens;
        tens /= 10;
      }
    }
    int sqr = sqrt(actualnum);
    if (sqr * sqr == actualnum) {
      minn = min(minn, (int)n.size() - (int)bs.count());
    }
  }
  if (minn == 10000000) {
    cout << -1;
  } else {
    cout << minn;
  }
  return 0;
}
