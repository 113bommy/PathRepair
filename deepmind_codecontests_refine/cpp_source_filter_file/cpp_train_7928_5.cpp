#include <bits/stdc++.h>
const int M = 1e9 + 7;
const int N = 5e5 + 5;
using namespace std;
long long int cnt(0), n, m, x, y, t, i, j, temp, k, ans(0), sum(0), mn(M),
    mx(-9e9);
vector<long long int> v[33];
long long int a[33];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    v[s[i] - 'a'].push_back(i + 1);
  }
  cin >> m;
  while (m--) {
    ans = 0;
    string ss;
    long long int temp;
    memset(a, 0, sizeof(a));
    cin >> ss;
    for (i = 0; i < ss.size(); i++) {
      ans = max(ans, v[ss[i] - 'a'][a[ss[i] - 'a']]);
    }
    cout << ans << endl;
  }
}
