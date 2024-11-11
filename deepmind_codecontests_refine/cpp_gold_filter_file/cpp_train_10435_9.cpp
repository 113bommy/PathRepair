#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.0);
using cd = complex<double>;
void fft(vector<cd>& a, bool invert) {
  long long n = a.size();
  for (long long i = 1, j = 0; i < n; i++) {
    long long bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (long long len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (long long i = 0; i < n; i += len) {
      cd w(1);
      for (long long j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (cd& x : a) x /= n;
  }
}
vector<cd> multiply(vector<cd> const& a, vector<cd> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  long long n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (long long i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);
  vector<cd> result(n);
  for (long long i = 0; i < n; i++) result[i] = fa[i];
  return result;
}
long long p[26];
bool sameCycle[400005];
long long lps[400005];
long long vis[26];
long long ind[26];
vector<long long> cur;
long long pos[26];
long long len[26];
vector<long long> prefix(vector<long long> temp) {
  long long len = temp.size();
  vector<long long> ans;
  ans.resize(len);
  ans[0] = 0;
  for (long long i = 1; i < len; ++i) {
    long long j = ans[i - 1];
    while (j > 0 && temp[i] != temp[j]) {
      j = ans[j - 1];
    }
    if (temp[i] == temp[j]) ++j;
    ans[i] = j;
  }
  return ans;
}
void dfs(long long node) {
  vis[node] = 1;
  cur.push_back(node);
  if (!vis[p[node]]) {
    dfs(p[node]);
  }
}
void solve() {
  string s, t;
  for (long long i = 0; i < 26; ++i) {
    cin >> p[i];
    --p[i];
  }
  cin >> t >> s;
  ;
  vector<long long> whichCycle;
  vector<long long> whichCycle2;
  for (long long i = 0; i < 26; ++i) {
    if (!vis[i]) {
      dfs(i);
      for (long long j = 0; j < (long long)cur.size(); ++j) {
        ind[cur[j]] = i;
        pos[cur[j]] = j;
      }
      len[i] = (long long)cur.size();
      cur.clear();
    }
  }
  whichCycle.resize((long long)s.size());
  whichCycle2.resize((long long)t.size());
  for (long long i = 0; i < (long long)s.size(); ++i) {
    whichCycle[i] = ind[s[i] - 'a'];
  }
  for (long long i = 0; i < (long long)t.size(); ++i) {
    whichCycle2[i] = ind[t[i] - 'a'];
  }
  long long m = (long long)whichCycle2.size();
  whichCycle2.push_back(-1);
  for (long long i : whichCycle) {
    whichCycle2.push_back(i);
  }
  vector<long long> ret = prefix(whichCycle2);
  for (long long i = m + 1; i < (long long)whichCycle2.size(); ++i) {
    if (ret[i] == m) {
      sameCycle[i - 2 * m] = 1;
    }
  }
  vector<cd> a((long long)s.size()), b((long long)t.size());
  for (long long i = 0; i < (long long)s.size(); ++i) {
    long long k = len[ind[s[i] - 'a']];
    long long n = pos[s[i] - 'a'];
    a[i].real(cos(-PI * (2 * n - 1) / k));
    a[i].imag(sin(-PI * (2 * n - 1) / k));
  }
  for (long long i = 0; i < (long long)t.size(); ++i) {
    long long k = len[ind[t[i] - 'a']];
    long long n = pos[t[i] - 'a'];
    b[i].real(cos(2 * PI * n / k));
    b[i].imag(sin(2 * PI * n / k));
  }
  reverse(b.begin(), b.end());
  vector<cd> res = multiply(a, b);
  double reqd = 0;
  for (long long i = 0; i < (long long)b.size(); ++i) {
    long long k = len[ind[t[i] - 'a']];
    reqd += cos(PI / k);
  }
  for (long long i = (long long)b.size() - 1; i < (long long)a.size(); ++i) {
    double error = abs(real(res[i]) - reqd);
    if (error < 1e-5) {
      cout << sameCycle[i - (long long)b.size() + 1];
    } else
      cout << 0;
  }
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
