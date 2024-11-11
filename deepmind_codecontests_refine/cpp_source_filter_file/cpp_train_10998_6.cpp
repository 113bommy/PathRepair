#include <bits/stdc++.h>
using namespace std;
long long n, x, d;
vector<long long> v, t;
set<long long> cur;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n && cin >> x; i++) v.push_back(x);
  for (int i = 0; i < n && cin >> x; i++) t.push_back(x);
  for (int i = 0; i < n; i++) {
    long long ans = 0;
    cur.insert(v[i] + d);
    long long prevd = d;
    d += t[i];
    while (cur.size()) {
      long long top = *cur.begin();
      if (top <= d) {
        ans += top - prevd;
        cur.erase(cur.begin());
      } else
        break;
    }
    ans += cur.size() * t[i];
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}
