#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double pi = acosl(-1);
const int maxn = 105;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const long double eps = 1e-8;
int n;
string s, t;
int cnt[26][2];
vector<int> ans;
void shift(int x) {
  if (x == 0) return;
  ans.push_back(x);
  string sub1 = t.substr(0, n - x), sub2 = t.substr(n - x);
  reverse(sub2.begin(), sub2.end());
  t = sub2 + sub1;
}
int main() {
  scanf("%d", &n);
  cin >> t >> s;
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a'][0]++;
    cnt[t[i] - 'a'][1]++;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i][0] != cnt[i][1]) {
      printf("-1");
      return 0;
    }
  }
  char mid = s[n / 2];
  int l = n / 2, r = n / 2, flip = 0;
  for (int i = 0; i < n; i++)
    if (t[i] == mid) {
      shift(n - i - 1);
      shift(1);
      break;
    }
  while (l > 0 || r < n - 1) {
    int len = r - l + 1;
    if (flip) {
      char tar = s[r + 1];
      for (int i = n - 1; i >= 0; i--)
        if (t[i] == tar) {
          shift(n - i);
          shift(i - len);
          shift(len + 1);
          break;
        }
      r++;
    } else {
      char tar = s[l - 1];
      for (int i = n - 1; i >= 0; i--)
        if (t[i] == tar) {
          shift(n - i);
          shift(i - len);
          shift(len + 1);
          break;
        }
      l--;
    }
    flip ^= 1;
  }
  if (t != s) shift(n);
  assert(t == s);
  printf("%d\n", (int)ans.size());
  for (auto i : ans) printf("%d ", i);
  return 0;
}
