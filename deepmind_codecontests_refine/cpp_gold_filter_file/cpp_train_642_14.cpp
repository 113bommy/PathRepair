#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
const ll MODBASE = 1000000007LL;
const int MAXN = 200010;
const int MAXM = 200010;
const int MAXK = 110;
const int MAXQ = 200010;
vector<int> a[MAXN];
int t, n;
priority_queue<int, vector<int>, greater<int> > h;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = (0); i <= (n - 1); i++) a[i].clear();
    for (int i = (1); i <= (n); i++) {
      int m, c;
      cin >> m >> c;
      a[m].emplace_back(c);
    }
    while (!h.empty()) h.pop();
    int prevSum = 0;
    int now = n;
    ll res = 0;
    for (int i = (n - 1); i >= (0); i--) {
      for (int j = (0); j <= (int((a[i]).size()) - 1); j++) h.push(a[i][j]);
      now -= int((a[i]).size());
      while (now + prevSum < i && !h.empty()) {
        int g = h.top();
        h.pop();
        prevSum++;
        res += g;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
