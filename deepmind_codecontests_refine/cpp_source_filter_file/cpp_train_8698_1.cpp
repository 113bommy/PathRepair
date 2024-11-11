#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod1 = 889930273;
const unsigned long long mod2 = 889930273;
const unsigned long long s1 = 131;
const int N = 3e6;
unsigned long long pm1[N], pm2[N];
pair<unsigned long long, unsigned long long> strhash[N];
void init(char *s, int len) {
  pm1[0] = pm2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pm1[i] = pm1[i - 1] * s1 % mod1;
    pm2[i] = pm2[i - 1] * s1 % mod2;
  }
  strhash[0] = pair<unsigned long long, unsigned long long>(s[0] * pm1[0],
                                                            s[0] * pm2[0]);
  for (int i = 1; i < len; ++i) {
    strhash[i] = pair<unsigned long long, unsigned long long>(
        (strhash[i - 1].first + s[i] * pm1[i]) % mod1,
        (strhash[i - 1].second + s[i] * pm2[i]) % mod2);
  }
}
unsigned long long qpow(unsigned long long a, unsigned long long k,
                        const unsigned long long &mod) {
  unsigned long long res = 1;
  while (k) {
    if (k & 1) res = res * a % mod;
    a = a * a % mod;
    k >>= 1;
  }
  return res;
}
pair<unsigned long long, unsigned long long> shash(int l, int r) {
  if (l == 0) return strhash[r];
  unsigned long long one = strhash[r].first;
  one = (one - strhash[l - 1].first + mod1) % mod1;
  one = one * qpow(pm1[l], mod1 - 2, mod1) % mod1;
  unsigned long long two = strhash[r].second;
  two = (two - strhash[l - 1].second + mod2) % mod2;
  two = two * qpow(pm2[l], mod2 - 2, mod2) % mod2;
  return make_pair(one, two);
}
pair<unsigned long long, unsigned long long> ghash(char *s, int k) {
  unsigned long long r1 = 0, r2 = 0;
  for (int i = 0; i < k; ++i) {
    r1 = (r1 + s[i] * pm1[i]) % mod1;
    r2 = (r2 + s[i] * pm2[i]) % mod2;
  }
  return pair<unsigned long long, unsigned long long>(r1, r2);
}
map<pair<unsigned long long, unsigned long long>, int> mp;
bool used[N];
char s[N];
unsigned long long sh[N];
int main(int argc, const char *argv[]) {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  int len = n * k;
  for (int i = 0; i < len; ++i) {
    s[i + len] = s[i];
  }
  init(s, len * 2);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%s", s);
    pair<unsigned long long, unsigned long long> res = ghash(s, k);
    mp[res] = i;
  }
  vector<int> ans;
  for (int i = 0; i < k; ++i) {
    for (int x : ans) used[x] = 0;
    ans.clear();
    for (int j = 0; j < n; ++j) {
      pair<unsigned long long, unsigned long long> tar =
          shash(i + j * k, i + (j + 1) * k - 1);
      if (mp.find(tar) == mp.end() || used[mp[tar]]) break;
      int id = mp[tar];
      used[id] = 1;
      ans.push_back(id);
      if (j == n - 1) {
        puts("YES");
        for (int x : ans) printf("%d ", x);
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
