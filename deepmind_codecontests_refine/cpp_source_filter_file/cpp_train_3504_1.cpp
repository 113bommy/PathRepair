#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, ll>;
const int maxn = 1e5 + 5;
ll b[maxn], n, sum;
ll ans[maxn], m;
multiset<ll> s;
int main() {
  while (cin >> n) {
    sum = 0;
    s.clear();
    m = 0;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      s.insert(b[i]);
    }
    while (!s.empty()) {
      bool f = 0;
      for (int i = 0; i <= 61; i++) {
        if (!((sum >> i) & 1)) {
          auto it = s.lower_bound(1 << i);
          if (it == s.end() || (sum ^ (*it)) < sum)
            continue;
          else {
            ans[++m] = *it;
            sum ^= *it;
            s.erase(it);
            f = 1;
            break;
          }
        }
      }
      if (!f) {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
}
