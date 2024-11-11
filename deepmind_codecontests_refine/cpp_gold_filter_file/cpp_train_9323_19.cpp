#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int Inf = 1e9 + 1;
const long long Mod = 1e9 + 7;
int n, a, b, k, q, l;
vector<int> ans;
string s;
int main() {
  cin >> n >> a >> b >> k;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      q += (i - l) / b;
      l = i + 1;
    }
  }
  q += (n - l) / b;
  l = n;
  while (q >= a) {
    for (int i = l - 1; i >= max(0, l - b); --i)
      if (s[i] == '1') l = i;
    if (l - b + 1 < 1) {
      cout << "-1";
      return 0;
    }
    ans.push_back(l - b + 1);
    l -= b;
    --q;
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
  return 0;
}
