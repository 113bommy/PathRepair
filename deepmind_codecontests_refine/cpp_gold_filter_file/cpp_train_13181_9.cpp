#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;
const double EPS = 1e-8;
const long double EUL = 2.71828182845904523536;
const long double PII = 3.14159265358979323846;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  while (cin >> n >> k) {
    int upto = 1 << k;
    vector<int> a(upto);
    while (n--) {
      int x = 0;
      for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        x |= (temp << i);
      }
      a[x] = 1;
    }
    bool oui = false;
    for (int i = 0; i < upto; i++) {
      for (int j = i; j < upto; j++)
        if (a[i] && a[j] && !(i & j)) {
          oui = true;
          break;
        }
    }
    cout << (oui ? "YES" : "NO") << endl;
  }
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
