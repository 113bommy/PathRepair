#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 123;
const int mod = (int)1e9 + 7;
const long long INF = (long long)1e18;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int t, a, ali = 0;
    set<int> s;
    cin >> t;
    for (int i = 0; i < t; i++) {
      cin >> a;
      s.insert(a);
    }
    while (!s.empty()) {
      int en = *s.rbegin();
      s.erase(en);
      if (en % 2 == 0) {
        s.insert(en / 2);
        ali++;
      }
    }
    cout << max(ali, 0) << endl;
  }
}
