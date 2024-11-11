#include <bits/stdc++.h>
using namespace std;
const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int DY[] = {0, 1, 0, -1, 1, -1, -1, 1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long sqr(long long x) { return x * x; }
long long sqr(int x) { return (long long)x * x; }
double sqr(double x) { return x * x; }
long double sqr(long double x) { return x * x; }
mt19937 mmtw(960172);
long long rnd(long long x, long long y) {
  static uniform_int_distribution<long long> d;
  return d(mmtw) % (y - x + 1) + x;
}
const int N = 3033;
int n;
string v1[N], v2[N];
string a1, a2;
string sp1, sp2;
int z[N * 2];
void zf(string const& s) {
  z[0] = 0;
  int ir = 0;
  int n = ((int)((s).size()));
  for (int i = 1; i < n; ++i) {
    if (i < ir + z[ir])
      z[i] = min(ir + z[ir] - i, z[i - ir]);
    else
      z[i] = 0;
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] > ir + z[ir]) ir = i;
  }
}
int main() {
  ios::sync_with_stdio(false);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    static char buf[N];
    scanf("%s", buf);
    v1[i] = buf;
  }
  for (int i = 0; i < n; ++i) {
    static char buf[N];
    scanf("%s", buf);
    v2[i] = buf;
    if (v1[i] == v2[i]) continue;
    int x1 = 0;
    while (v1[i][x1] == v2[i][x1]) ++x1;
    int x2 = ((int)((v1[i]).size())) - 1;
    while (v1[i][x2] == v2[i][x2]) --x2;
    string ca1 = v1[i].substr(x1, x2 - x1 + 1);
    string ca2 = v2[i].substr(x1, x2 - x1 + 1);
    if (a1.empty()) {
      a1 = ca1;
      a2 = ca2;
      sp1 = v1[i].substr(0, x1);
      reverse((sp1).begin(), (sp1).end());
      sp2 = v1[i].substr(x2 + 1, ((int)((v1[i]).size())) - (x2 + 1));
    } else {
      if (a1 != ca1 || a2 != ca2) {
        cout << "NO\n";
        return 0;
      }
      for (int j = 0; j < ((int)((sp1).size())); ++j)
        if (x1 - 1 - j < 0 || sp1[j] != v1[i][x1 - 1 - j]) {
          sp1.erase(sp1.begin() + j, sp1.end());
          break;
        }
      for (int j = 0; j < ((int)((sp2).size())); ++j)
        if (x2 + 1 + j >= ((int)((v1[i]).size())) ||
            sp2[j] != v1[i][x2 + 1 + j]) {
          sp2.erase(sp2.begin() + j, sp2.end());
          break;
        }
    }
  }
  reverse((sp1).begin(), (sp1).end());
  string ans1 = sp1 + a1 + sp2;
  string ans2 = sp1 + a2 + sp2;
  for (int i = 0; i < n; ++i) {
    string ss = ans1 + '+' + v1[i];
    zf(ss);
    int pos = -1;
    for (int j = 0; j < ((int)((v1[i]).size())); ++j)
      if (((int)((ans1).size())) == z[((int)((ans1).size())) + 1 + j]) {
        pos = j;
        break;
      }
    if (pos == -1) {
      if (v1[i] != v2[i]) {
        cout << "NO\n";
        return 0;
      }
    } else {
      string nv = v1[i];
      for (int j = 0; j < ((int)((ans1).size())); ++j) nv[pos + j] = ans2[j];
      if (nv != v2[i]) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  cout << ans1 << "\n";
  cout << ans2 << "\n";
  return 0;
}
