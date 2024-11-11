#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void zz() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
int32_t main() {
  zz();
  long long v[19] = {4,  9,  25, 49, 2,  3,  5,  7,  11, 13,
                     17, 19, 23, 29, 31, 37, 41, 43, 47};
  long long cnt = 0;
  bool b = 0;
  for (long long i = 0; i < 25; i++) {
    cout << v[i] << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s[0] == 'y') {
      if (i < 4) {
        cout << "composite" << endl;
        return 0;
      }
      cnt += 1;
    }
    if (cnt > 1) {
      b = 1;
      break;
    }
  }
  if (b)
    cout << "composite" << endl;
  else
    cout << "prime" << endl;
}
