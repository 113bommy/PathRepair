#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
void fast_in_out() {
  std::ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
}
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
const long double eps = 1e-9;
const int mod = 998244353;
const int N = 1e5 + 1, M = 318;
long long ar[21];
int cnty[12];
int main() {
  fast_in_out();
  int n;
  cin >> n;
  vector<string> v(n);
  int szy = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    reverse(v[i].begin(), v[i].end());
    cnty[v[i].size()]++;
  }
  for (int i = 0; i < n; i++) {
    string num = v[i];
    for (int sz = 1; sz < num.size(); sz++) {
      for (int j = sz; j < num.size() && cnty[sz]; j++) {
        int nsz = sz + j + 1;
        long long x = (num[j] - '0');
        ar[nsz] += (x * (cnty[sz] * 2));
        ar[nsz] %= mod;
      }
      for (int j = 0, nsz = 1; j < sz && cnty[sz]; j++, nsz += 2) {
        long long x = (num[j] - '0');
        ar[nsz] += (x * cnty[sz]);
        ar[nsz + 1] += (x * cnty[sz]);
        ar[nsz] %= mod;
        ar[nsz + 1] %= mod;
      }
    }
    int nn = 0;
    for (int sz = num.size(); sz < 12; sz++) {
      nn += cnty[sz];
    }
    for (int j = 0, nsz = 1; j < num.size(); j++, nsz += 2) {
      int x = (num[j] - '0');
      ar[nsz] += (x * nn);
      ar[nsz + 1] += (x * nn);
      ar[nsz] %= mod;
      ar[nsz + 1] %= mod;
      szy = max(szy, nsz + 1);
    }
  }
  long long ret = 0, po = 1;
  for (int i = 1; i <= szy; i++) {
    if (i != 1) po *= 10;
    po %= mod;
    ret += (po * ar[i]);
    ret %= mod;
  }
  cout << ret << '\n';
  return 0;
}
