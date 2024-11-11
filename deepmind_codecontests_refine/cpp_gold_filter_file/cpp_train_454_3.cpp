#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1000 + 100;
int n, ind[maxn], a[maxn], num[maxn], ans = 0;
vector<int> v;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    ind[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    while (v.size() && v.back() < a[i]) {
      if (v.size() > 1)
        num[v[v.size() - 2]] = max(num[v[v.size() - 2]], num[v[v.size() - 1]]);
      v.pop_back();
    }
    if (v.size()) num[v.back()]++;
    v.push_back(a[i]);
  }
  for (int i = 0; i < n; i++) ans = max(ans, num[i]);
  cout << ans << endl;
  return 0;
}
