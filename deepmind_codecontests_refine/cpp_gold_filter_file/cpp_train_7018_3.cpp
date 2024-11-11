#include <bits/stdc++.h>
using namespace std;
class Div1A {
 public:
  void solve(void) {
    int m;
    cin >> m;
    int maxN = m + 1;
    vector<int> type(maxN, 0);
    vector<int> x(maxN, 0);
    vector<int> cnt(maxN, 0);
    vector<long long> nd(maxN, 0);
    vector<int> a;
    for (int(i) = (0); i < (m); i++) {
      cin >> type[i];
      if (type[i] == 1) {
        cin >> x[i];
        nd[i + 1] = nd[i] + 1;
      } else {
        cin >> x[i] >> cnt[i];
        nd[i + 1] = nd[i] + x[i] * cnt[i];
      }
    }
    int n;
    cin >> n;
    for (int(i) = (0); i < (n); i++) {
      long long k;
      cin >> k;
      while (true) {
        int l = lower_bound((nd).begin(), (nd).end(), k) - nd.begin();
        int p = l - 1;
        if (type[p] == 1) {
          cout << x[p] << endl;
          break;
        }
        k = (k - nd[p] - 1) % x[p] + 1;
      }
    }
  }
};
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  auto obj = new Div1A();
  obj->solve();
  delete obj;
  return 0;
}
