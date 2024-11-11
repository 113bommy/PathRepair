#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using db = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using vpd = vector<pdb>;
using umi = unordered_map<int, int>;
using uml = unordered_map<ll, ll>;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v);
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v);
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v);
template <typename T>
inline istream &operator>>(istream &in, vector<T> &a);
const int mod = 1e9 + 7;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_case = 1;
  while (test_case--) {
    int n;
    cin >> n;
    str res = "ROYGBIV";
    n -= 7;
    for (int i = 0; i < n; i++) res += res[i % 4 + 3];
    cout << res << "\n";
  }
  return 0;
}
