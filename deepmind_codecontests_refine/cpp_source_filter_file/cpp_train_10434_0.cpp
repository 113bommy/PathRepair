#include <bits/stdc++.h>
using namespace std;
const int QQ = 3e5 + 10;
const int maxN = (1 << 21) + 100;
const int maxM = 3e5 + 100;
const long long oo = 4e18;
const int INF = 2e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 311;
const long double du = 1e-9;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
void doc() {
  freopen(
      "solve"
      ".inp",
      "r", stdin);
  freopen(
      "solve"
      ".out",
      "w", stdout);
}
void solve() {
  int T;
  cin >> T;
  const long long limit = 1e16;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<long long> pw;
    long long s = 1;
    while (s <= limit) {
      pw.push_back(s);
      s *= k;
    }
    int sz = (int)pw.size();
    vector<int> Used(sz, 0);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < sz; j++) {
        int bit = (a[i] / pw[j]) % k;
        if (bit == 0) continue;
        if (bit != 1)
          ok = false;
        else {
          if (Used[j]) ok = false;
          Used[j] = 1;
        }
      }
    }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main(int argc, char *argv[]) {
  srand(time(nullptr));
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
