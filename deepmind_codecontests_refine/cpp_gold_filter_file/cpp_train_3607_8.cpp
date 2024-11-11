#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int mod = 1e9 + 7;
int l, r, n, cnt[N], pos;
string a, b, s1, s2;
vector<int> ans;
void shift(int x) {
  ans.push_back(x);
  if (l < n - x) {
    l = x + l;
  } else
    l = n - l - 1;
  if (r < n - x) {
    r = x + r;
  } else
    r = n - r - 1;
  a = s2.substr(0, n - x);
  b = s2.substr(n - x, n);
  reverse(b.begin(), b.end());
  s2 = b + a;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s2 >> s1;
  for (int i = (0); i < ((int)s1.size()); i++) cnt[s1[i] - 'a']++;
  for (int i = (0); i < ((int)s2.size()); i++) cnt[s2[i] - 'a']--;
  for (int i = (0); i < (26); i++)
    if (cnt[i]) {
      cout << -1 << "\n";
      return 0;
    }
  for (int i = (0); i < ((int)s2.size()); i++)
    if (s2[i] == s1[0]) {
      l = r = i;
      break;
    }
  for (int i = (1); i < (n); i++) {
    for (int j = (0); j < (n); j++)
      if ((j < l || j > r) && s2[j] == s1[i]) {
        pos = j;
        break;
      }
    if (pos < l) {
      shift(n - pos - 1);
      shift(1);
      shift(n - r);
    } else {
      shift(n - pos - 1);
      shift(n);
      shift(n - r);
    }
    r++;
  }
  cout << (int)ans.size() << "\n";
  for (int i = (0); i < ((int)ans.size()); i++) cout << ans[i] << " ";
  return 0;
}
