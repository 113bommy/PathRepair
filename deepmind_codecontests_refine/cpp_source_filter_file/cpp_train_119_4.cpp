#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 5;
const long long Inf = 2e9;
const long long mod = 998244353;
int n, mx;
int cnt[20];
long long pos[50];
vector<string> v;
void add(string s) {
  for (int l = s.length(); l < 10; l++) {
    int align = 2 * mx - (l + s.length());
    int offset = l - s.length();
    for (int i = 0; i < s.length(); i++) {
      pos[offset + align + 2 * i + 1] += 1ll * (s[i] - '0') * cnt[l];
      pos[offset + align + 2 * i + 1] %= mod;
      pos[offset + align + 2 * i + 2] += 1ll * (s[i] - '0') * cnt[l];
      pos[offset + align + 2 * i + 2] %= mod;
    }
  }
  for (int l = 1; l < s.length(); l++) {
    int align = 2 * mx - (l + s.length());
    int offset = s.length() - l;
    for (int i = 0; i < offset; i++) {
      pos[1 + i + align] += 2ll * (s[i] - '0') * cnt[l];
      pos[1 + i + align] %= mod;
    }
    for (int i = offset; i < s.length(); i++) {
      pos[2 * (i - offset) + offset + 1 + align] += 1ll * (s[i] - '0') * cnt[l];
      pos[2 * (i - offset) + offset + 1 + align] %= mod;
      pos[2 * (i - offset) + offset + 2 + align] += 1ll * (s[i] - '0') * cnt[l];
      pos[2 * (i - offset) + offset + 2 + align] %= mod;
    }
  }
}
int main() {
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
    cnt[s.length()]++;
    mx = max(mx, (int)s.length());
  }
  for (int i = 0; i < v.size(); i++) add(v[i]);
  long long ans = 0;
  for (int i = 1; i <= mx * 2; i++) {
    ans *= 10;
    ans %= mod;
    ans += pos[i];
    ans %= mod;
  }
  cout << ans << endl;
}
