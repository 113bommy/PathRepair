#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> pos[30];
int d[30], a[N], tr[N], n;
void string_update(int x) {
  while (x <= n) {
    tr[x]++;
    x += (x & -x);
  }
}
int query(int x) {
  int res = 0;
  while (x) {
    res += tr[x];
    x -= (x & -x);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long ans = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = n - 1; i >= 0; i--) {
    pos[s[i] - 'a'].push_back(n - i);
  }
  for (int i = 0; i < n; i++) {
    a[i] = pos[s[i] - 'a'][d[s[i] - 'a']];
    d[s[i] - 'a']++;
  }
  for (int i = n - 1; i >= 0; i--) {
    ans += query(a[i] - 1);
    string_update(a[i]);
  }
  cout << ans;
  return 0;
}
