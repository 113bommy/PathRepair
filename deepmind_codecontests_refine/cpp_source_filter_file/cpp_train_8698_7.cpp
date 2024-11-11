#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2000005;
long long mod[2] = {(long long)1e9 + 7, (long long)1e9 + 9},
          base[2] = {696969, 69420};
long long p[2][maxn], hsh[2][maxn];
string s;
void initHash() {
  for (long long i = 0; i < 2; i++) {
    p[i][0] = 1;
    for (long long j = 1; j < maxn; j++)
      p[i][j] = (p[i][j - 1] * base[i]) % mod[i];
    hsh[i][0] = s[0] - 'a' + 1;
    for (long long j = 1; j < s.length(); j++)
      hsh[i][j] = (hsh[i][j - 1] + ((s[j] - 'a' + 1) * p[i][j])) % mod[i];
  }
}
long long getHsh(long long l, long long r, long long t) {
  long long res = hsh[t][r];
  if (l != 0) res -= hsh[t][l - 1];
  while (res < 0) res += mod[t];
  res = (res * p[t][maxn - 2 - l]) % mod[t];
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k >> s;
  s += s;
  initHash();
  long long g;
  cin >> g;
  map<pair<long long, long long>, vector<long long>> m;
  for (long long q = 0; q < g; q++) {
    string str;
    cin >> str;
    pair<long long, long long> pa;
    for (long long i = 0; i < 2; i++) {
      long long val = str[0] - 'a' + 1;
      for (long long j = 1; j < str.length(); j++)
        val = (val + ((str[j] - 'a' + 1) * p[i][j])) % mod[i];
      val = (val * p[i][maxn - 2]) % mod[i];
      if (i == 0)
        pa.first = val;
      else
        pa.second = val;
    }
    m[pa].push_back(q);
  }
  for (long long i = 0; i < n; i++) {
    map<pair<long long, long long>, long long> cnt;
    vector<long long> vec;
    bool ok = true;
    for (long long j = i; j < i + n * k; j += k) {
      pair<long long, long long> pa = {getHsh(j, j + k - 1, 0),
                                       getHsh(j, j + k - 1, 1)};
      if (m.count(pa) == 0 || cnt[pa] == m[pa].size()) {
        ok = false;
        break;
      }
      vec.push_back(m[pa][cnt[pa]]);
      cnt[pa]++;
    }
    if (ok) {
      cout << "YES\n";
      for (long long j : vec) cout << j + 1 << ' ';
      cout << '\n';
      exit(0);
    }
  }
  cout << "NO\n";
}
