#include <bits/stdc++.h>
using namespace std;
int mod = 10487;
const int maxn = 1e5 + 10;
const int maxL = 10 + 10;
map<int, int> cnt;
set<pair<int, int> > st;
int n, k, ar[maxn];
void chng(int x, int goh) {
  st.erase(pair<int, int>(cnt[x], -x));
  cnt[x] += goh;
  if (cnt[x] > 0) st.insert(pair<int, int>(cnt[x], -x));
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> ar[i];
  for (int i = 0; i < k; i++) chng(ar[i], +1);
  for (int i = 0; i < (n - k + 1); chng(ar[i + k], +1), chng(i[ar], -1), i++) {
    if (st.begin()->first == 1)
      cout << -st.begin()->second << '\n';
    else
      cout << "Nothing" << '\n';
  }
  return 0;
}
