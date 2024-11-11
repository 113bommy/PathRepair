#include <bits/stdc++.h>
#pragma "SINITSIN_PITUH"
using namespace std;
const long long MAXN = 2e5 + 47, mod = 1e9 + 7, inf = 1e9 + 47;
struct st_hash {
  long long n;
  long long t[2];
  vector<long long> h[2];
  vector<long long> p[2];
  long long B[2], m[2];
  st_hash(string st = "") {
    B[0] = B[1] = 10;
    m[0] = 1e9 + 57, m[1] = 1e9 + 123;
    n = (long long)(st.size());
    for (long long i = 0; i < 2; i++)
      h[i].resize(n + 1, 0), p[i].resize(n + 1, 0);
    p[0][0] = p[1][0] = 1;
    for (long long j = 0; j < 2; j++)
      for (long long i = 1; i < n + 1; i++)
        p[j][i] = (p[j][i - 1] * B[j]) % m[j];
    for (long long j = 0; j < 2; j++)
      for (long long i = 1; i < n + 1; i++)
        h[j][i] = ((h[j][i - 1] * B[j]) % m[j] + st[i - 1] - '0') % m[j];
  }
  pair<long long, long long> get_hash(long long l, long long r) {
    pair<long long, long long> res;
    for (long long j = 0; j < 2; j++)
      t[j] =
          (h[j][r + 1] - (h[j][l] * p[j][r - l + 1]) % m[j] + m[j] * 5) % m[j];
    res.first = t[0], res.second = t[1];
    return res;
  }
};
string vdig;
st_hash dig;
long long n;
void read() {
  cin >> vdig;
  n = (long long)(vdig.size());
  dig = st_hash(vdig);
}
bool f(long long mid, long long start) {
  if (mid < 0 || mid + 1 >= start) return false;
  pair<long long, long long> a = dig.get_hash(0LL, mid),
                             b = dig.get_hash(mid + 1, start - 1),
                             c = dig.get_hash(start,
                                              (long long)(vdig.size()) - 1);
  if (mid >= 1 && vdig[0] == '0') return false;
  if (start - 1 - (mid + 1) + 1 > 1 && vdig[mid + 1] == '0') return false;
  if (n - 1 - start + 1 > 1 && vdig[start] == '0') return false;
  a.first += b.first, a.second += b.second;
  a.first %= dig.m[0], a.second %= dig.m[1];
  if (a == c) return true;
  return false;
}
void solve() {
  for (long long start = 2; start < (long long)(vdig.size()); start++) {
    long long mid = (start) / 2;
    if (f(mid, start)) {
      for (long long i = 0; i < mid + 1; i++) cout << vdig[i];
      cout << "+";
      for (long long i = mid + 1; i < start; i++) cout << vdig[i];
      cout << "=";
      for (long long i = start; i < n; i++) cout << vdig[i];
      return;
    }
    if (f(mid - 1, start)) {
      for (long long i = 0; i < mid; i++) cout << vdig[i];
      cout << "+";
      for (long long i = mid; i < start; i++) cout << vdig[i];
      cout << "=";
      for (long long i = start; i < n; i++) cout << vdig[i];
      return;
    }
    if (f(mid + 1, start)) {
      for (long long i = 0; i < mid + 2; i++) cout << vdig[i];
      cout << "+";
      for (long long i = mid + 2; i < start; i++) cout << vdig[i];
      cout << "=";
      for (long long i = start; i < n; i++) cout << vdig[i];
      return;
    }
    if (f(0, start)) {
      for (long long i = 0; i < 1; i++) cout << vdig[i];
      cout << "+";
      for (long long i = 1; i < start; i++) cout << vdig[i];
      cout << "=";
      for (long long i = start; i < n; i++) cout << vdig[i];
      return;
    }
    if (f(start - 2, start)) {
      for (long long i = 0; i < start - 1; i++) cout << vdig[i];
      cout << "+";
      for (long long i = start - 1; i < start; i++) cout << vdig[i];
      cout << "=";
      for (long long i = start; i < n; i++) cout << vdig[i];
      return;
    }
    long long len = n - start;
    if (f(len, start)) {
      for (long long i = 0; i < len + 1; i++) cout << vdig[i];
      cout << "+";
      for (long long i = len + 1; i < start; i++) cout << vdig[i];
      cout << "=";
      for (long long i = start; i < n; i++) cout << vdig[i];
      return;
    }
    if (f(len - 1, start)) {
      for (long long i = 0; i < len; i++) cout << vdig[i];
      cout << "+";
      for (long long i = len; i < start; i++) cout << vdig[i];
      cout << "=";
      for (long long i = start; i < n; i++) cout << vdig[i];
      return;
    }
    len = start - len;
    if (f(len, start)) {
      for (long long i = 0; i < len + 1; i++) cout << vdig[i];
      cout << "+";
      for (long long i = len + 1; i < start; i++) cout << vdig[i];
      cout << "=";
      for (long long i = start; i < n; i++) cout << vdig[i];
      return;
    }
    if (f(len - 1, start)) {
      for (long long i = 0; i < len; i++) cout << vdig[i];
      cout << "+";
      for (long long i = len; i < start; i++) cout << vdig[i];
      cout << "=";
      for (long long i = start; i < n; i++) cout << vdig[i];
      return;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  read();
  solve();
}
