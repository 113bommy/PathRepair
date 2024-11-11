#include <bits/stdc++.h>
using namespace std;
void solve() {}
long long res1[500000], res2[500000];
int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  map<int, int> mp;
  int cnt_minus = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mp[b[i] - i]++;
    if (b[i] - i < 0) cnt_minus++;
  }
  int numgr = mp.size();
  for (int i = 0; i < n; i++) {
    if (b[i] - i >= 0) {
      res1[b[i] - i] += b[i];
    } else {
      res2[abs(b[i] - i)] += b[i];
    }
  }
  long long ans = 0;
  for (int i = 0; i < 500000; i++) {
    ans = max(ans, res1[i]);
    ans = max(ans, res2[i]);
  }
  cout << ans << endl;
}
