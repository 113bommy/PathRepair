#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double eps = (1e-7);
int dcmp(long double x, long double y) {
  if (abs(x - y) < eps) return 0;
  if (x > y) return 1;
  return -1;
}
string pattern;
vector<int> pi;
int getNewLen(int len, char c) {
  while (len && c != pattern[len]) len = pi[len - 1];
  return len + (c == pattern[len]);
}
void buildPi() {
  pi.clear();
  pi.resize((int)(pattern).size());
  pi[0] = 0;
  for (int i = 1; i < (int)(pattern).size(); ++i) {
    pi[i] = getNewLen(pi[i - 1], pattern[i]);
  }
}
const int MOD = 1000000007;
long long mod(long long x) { return (x % MOD + MOD) % MOD; }
long long mult(long long a, long long b) { return mod((mod(a) * mod(b))); }
long long power(long long base, int exp) {
  long long ret = 1;
  for (; exp; exp /= 2) {
    if (exp & 1) ret = mult(ret, base);
    base = mult(base, base);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  cin >> pattern;
  vector<int> v(m);
  for (int i = 0; i < m; ++i) {
    cin >> v[i];
    v[i]--;
  }
  int lastEnd = -1;
  int cnt = 0;
  vector<bool> okSize((int)(pattern).size() + 1);
  buildPi();
  int len = pi.back();
  while (len) {
    okSize[len] = 1;
    len = pi[len - 1];
  }
  okSize[pattern.size()] = 1;
  for (int i = 0; i < m; ++i) {
    int l = v[i], r = l + (int)(pattern).size() - 1;
    if (l > lastEnd)
      cnt += (l - lastEnd - 1);
    else {
      int size = lastEnd - l + 1;
      if (!okSize[size]) {
        cout << 0 << '\n';
        return 0;
      }
    }
    lastEnd = r;
  }
  cnt += n - lastEnd - (lastEnd != n);
  cout << power(26, cnt) << '\n';
  return 0;
}
