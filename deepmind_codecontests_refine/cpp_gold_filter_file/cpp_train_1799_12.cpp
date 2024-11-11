#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const double pi = acos(-1);
const long long inf = 0x3f3f3f3f;
using namespace std;
long long t, n;
long long a[31] = {1,
                   6,
                   28,
                   120,
                   496,
                   2016,
                   8128,
                   32640,
                   130816,
                   523776,
                   2096128,
                   8386560,
                   33550336,
                   134209536,
                   536854528,
                   2147450880,
                   8589869056,
                   34359607296,
                   137438691328,
                   549755289600,
                   2199022206976,
                   8796090925056,
                   35184367894528,
                   140737479966720,
                   562949936644096,
                   2251799780130816,
                   9007199187632128,
                   36028796884746240,
                   144115187807420416,
                   576460751766552576,
                   2305843008139952128};
vector<long long> sum;
signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n;
    long long cnt = 0;
    while (n >= 0) {
      n -= a[cnt++];
    }
    cout << cnt - 1 << '\n';
  }
}
