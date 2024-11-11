#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  ;
  ll t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi a(n);
    map<int, int> m;
    for (long long i = 0; i < n; i += 1) {
      cin >> a[i];
      m[a[i]]++;
    }
    int amex = 0, bmex = 0;
    if ((m.begin())->first != 0) {
      cout << 0 << endl;
      continue;
    }
    for (auto i : m) {
      if ((i.first) - amex == 0) {
        amex = i.first + 1;
        i.second--;
      } else
        break;
      if ((i.second) && (i.first) - bmex == 0) {
        bmex = i.first + 1;
      }
    }
    cout << amex + bmex << endl;
  }
  return 0;
}
