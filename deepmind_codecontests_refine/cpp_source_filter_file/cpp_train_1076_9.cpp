#include <bits/stdc++.h>
using namespace std;
const unsigned long long seedpool[] = {239, 229};
const unsigned long long modpool[] = {1000000009, 998244353};
char str[500005];
int n;
struct Hash {
  unsigned long long seed, mod;
  vector<unsigned long long> p, h;
  Hash() {}
  Hash(unsigned long long *s, int &seed_index, int &mod_index) {
    seed = seedpool[seed_index];
    mod = modpool[mod_index];
    p.resize(n + 1), h.resize(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] * seed % mod;
    for (int i = 1; i <= n; i++)
      h[i] = (h[i - 1] * seed % mod + s[i - 1]) % mod;
  }
  unsigned long long get(int l, int r) {
    return (h[r] - h[l] * p[r - l] % mod + mod) % mod;
  }
  unsigned long long substr(int l, int m) { return get(l, l + m); }
} hasher[2];
unsigned long long a[500005];
unordered_map<int, int> mp;
vector<int> vec[500005];
vector<pair<int, int> > res;
int tot = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%llu", &a[i]);
    if (!mp[a[i]]) mp[a[i]] = ++tot;
    vec[mp[a[i]]].push_back(i);
  }
  for (int i = 0; i < 2; i++) {
    hasher[i] = Hash(a, i, i);
  }
  for (int i = 1; i <= tot; i++) {
    int sz = vec[i].size();
    for (int j = 0; j < sz; j++) {
      for (int k = j + 1; k < sz; k++) {
        int v = 1, Len = vec[i][k] - vec[i][j];
        if (vec[i][k] + Len > n) break;
        for (int L = 0; L < 2; L++) {
          if (hasher[L].substr(vec[i][j], Len) !=
              hasher[L].substr(vec[i][k], Len)) {
            v = 0;
            break;
          }
        }
        if (v) res.push_back(pair<int, int>(Len, vec[i][j]));
      }
    }
  }
  sort(res.begin(), res.end());
  int ans = 0;
  for (int i = 0; i < res.size(); i++) {
    if (res[i].second > ans || ans == 0) {
      ans = res[i].second + res[i].first;
    }
  }
  printf("%d\n", n - ans);
  for (int i = ans; i < n; i++) {
    printf("%llu ", a[i]);
  }
  return 0;
}
