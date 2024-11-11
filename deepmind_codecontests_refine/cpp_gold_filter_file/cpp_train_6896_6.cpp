#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
const ll inf = 1e9;
const ll INF = 2e18;
const int N = 2e6 + 66;
const int M = 5005;
string st;
int p[N];
void solve() {
  int n, k, L = -1, R = -1;
  cin >> n >> k;
  for (int i = 2; i <= n; ++i) {
    p[i] = i;
  }
  shuffle(p + 2, p + 1 + n, rnd);
  for (int rep = 0; rep < min(30, n - 1); ++rep) {
    int i = p[rep + 2];
    cout << "? 1 1\n1\n" << i << "\n";
    cout.flush();
    cin >> st;
    if (st == "SECOND") {
      cout << "! 1\n";
      cout.flush();
      return;
    }
  }
  for (int len = 1; len * 2 <= n; len <<= 1) {
    cout << "? " << len << " " << len << "\n";
    for (int i = 1; i <= len; ++i) cout << i << " ";
    cout << "\n";
    for (int i = 1; i <= len; ++i) cout << len + i << " ";
    cout << "\n";
    cout.flush();
    cin >> st;
    if (st == "FIRST") {
      L = len + 1, R = len * 2;
      break;
    } else {
      L = len * 2 + 1, R = n;
    }
  }
  assert(R - L + 1 <= n / 2);
  while (L < R) {
    int M = (L + R) >> 1;
    int len = M - L + 1;
    cout << "? " << len << " " << len << "\n";
    for (int i = 1; i <= len; ++i) cout << i << " ";
    cout << "\n";
    for (int i = L; i <= M; ++i) cout << i << " ";
    cout << "\n";
    cout.flush();
    cin >> st;
    if (st == "FIRST") {
      R = M;
    } else {
      L = M + 1;
    }
  }
  cout << "! " << R << "\n";
  cout.flush();
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
