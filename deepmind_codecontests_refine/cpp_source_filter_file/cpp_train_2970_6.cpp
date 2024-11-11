#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
long long m, n, t, k, a[N], ans, b[N], tong, idx;
vector<pair<long long, long long> > v;
string s;
const long double pi = acos(-1);
map<string, string> mp;
void drill(string q, string asr) { mp[q] = asr; }
string query(string q) { return mp[q]; }
int count_permutation(vector<int> p) {
  n = p.size();
  for (int i = 1; i <= n; i++) a[i] = p[i - 1];
  b[0] = 1;
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1];
    long long mn = a[i], mx = 0;
    for (int j = i - 1; j > 0; j--) {
      mx = max(mx, a[j]);
      if (a[j] > mn && a[i] < mx) {
        b[i] += b[j - 1];
        if (b[i] >= mod) b[i] -= mod;
      } else
        mn = a[j];
    }
  }
  return b[n];
}
void sol() {
  cin >> n >> m;
  long double res = 1.0 / tan(pi / n) + 1.0 / tan(pi / (2 * n));
  res = n * m * m / res;
  cout << fixed << setprecision(10) << res;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  sol();
}
