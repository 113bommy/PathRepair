#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> lis;
int ps[N], pref[N], suff[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    --l;
    ps[l]++;
    ps[r]--;
  }
  for (int i = 0; i < m; i++)
    if (i) ps[i] += ps[i - 1];
  for (int i = 0; i < m; i++) {
    int ptr = upper_bound(lis.begin(), lis.end(), ps[i]) - lis.begin();
    if (ptr == (int)lis.size())
      lis.push_back(ps[ptr]);
    else
      lis[ptr] = ps[i];
    pref[i] = ptr + 1;
  }
  lis.clear();
  for (int i = m - 1; i >= 0; i--) {
    int ptr = upper_bound(lis.begin(), lis.end(), ps[i]) - lis.begin();
    if (ptr == (int)lis.size())
      lis.push_back(ps[ptr]);
    else
      lis[ptr] = ps[i];
    suff[i] = ptr + 1;
  }
  int ans = 0;
  for (int i = 0; i < m; i++) ans = max(ans, pref[i] + suff[i] - 1);
  cout << ans << endl;
}
