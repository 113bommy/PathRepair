#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
pair<int, int> L[maxn], R[maxn];
int cnt[maxn], a[maxn], n;
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (a[1] > 1) return cout << -1 << endl, 0;
  L[0] = R[0] = make_pair(1, 1);
  for (int i = 1; i < n; i++) {
    L[i] = L[i - 1];
    L[i].second++;
    R[i] = R[i - 1];
    R[i].second++;
    if (L[i].second > 5) L[i].first++, L[i].second = 1;
    if (R[i].second > 2) R[i].first++, R[i].second = 1;
    if (a[i] && (L[i].first > a[i] || R[i].first < a[i]))
      return cout << -1 << endl, 0;
    if (a[i]) L[i] = max(L[i], make_pair(a[i], 1));
    if (a[i]) R[i] = min(R[i], make_pair(a[i], 5));
  }
  pair<int, int> ans = R[n - 1];
  if (ans.second == 1) ans.first--, ans.second = 5;
  if (ans < L[n - 1]) return cout << -1 << endl, 0;
  cout << ans.first << endl;
  a[n - 1] = ans.first;
  cnt[ans.first] = 1;
  for (int i = n - 2; i >= 0; i--) {
    a[i] = min(a[i + 1], R[i].first);
    if (cnt[a[i]] == 5) a[i]--;
    cnt[a[i]]++;
  }
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  cout << endl;
  return 0;
}
