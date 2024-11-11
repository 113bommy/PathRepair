#include <bits/stdc++.h>
using namespace std;
string tout[6] = {"NO", "YES", "No", "Yes", "no", "yes"};
using vi = vector<int>;
using vll = vector<long long>;
using vld = vector<long double>;
using vch = vector<char>;
using mi = map<int, int>;
using mll = map<long long, long long>;
using msll = map<string, long long>;
using mlls = map<long long, string>;
using mchll = map<char, long long>;
using si = set<int>;
using pll = pair<long long, long long>;
using sll = set<long long>;
using pdd = pair<double, double>;
const long long INF = 1e9 + 5;
const long long MOD = 1e5;
const long long ARIGATO = 2e5 + 5;
const long long ASO = 1e18 + 5;
const long long ANI = 1e6 + 5;
const long long inf = -1e9;
const long long mod = -1e5;
const long long aso = -1e18;
const long long ISM = 1e4 + 5;
long long n, k, h, a[10000], g, i;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k >> h;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  if (a[n - k + 1] == a[n - k]) {
    cout << 0;
  } else {
    cout << a[n - k + 1] - 1 << " ";
  }
}
