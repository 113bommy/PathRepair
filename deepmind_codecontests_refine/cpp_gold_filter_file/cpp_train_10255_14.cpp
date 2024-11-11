#include <bits/stdc++.h>
using namespace ::std;
int ar[2005], ar2[2005], p1[2005], p2[2005], ans;
vector<pair<int, int>> v;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ar[i], p1[ar[i]] = i;
  for (int i = 0; i < n; i++) cin >> ar2[i], p2[ar2[i]] = i;
  for (int i = 0; i < n; i++)
    for (int i = 0; i < n; i++)
      for (int j = p1[ar2[i]] - 1, p = p1[ar2[i]]; j >= i; j--)
        if (p2[ar[j]] >= p)
          ans += p - j, v.push_back({p, j}), swap(p1[ar[j]], p1[ar[p]]),
              swap(ar[p1[ar[j]]], ar[p1[ar[p]]]), p = j;
  cout << ans << '\n';
  cout << v.size() << '\n';
  for (auto a : v) cout << a.second + 1 << ' ' << a.first + 1 << '\n';
}
