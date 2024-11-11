#include <bits/stdc++.h>
const int INF = 0x5f4f3f2f;
const int MOD = 1000000007;
const double PI = 3.141592653589793;
const double EPS = 0.0000000001;
using namespace std;
using ll = long long;
using un = unsigned;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using graph = vector<vector<ii>>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < (int)(v.size()); i++) {
    cin >> v[i];
  };
  vi s(n), u(n);
  s[0] = v[0];
  for (int i = 1; i < n; i++) {
    s[i] = s[i - 1] + v[i];
  }
  vi k = v;
  sort(v.begin(), v.end());
  u[0] = v[0];
  for (int i = 1; i < n; i++) {
    u[i] = u[i - 1] + v[i];
  }
  int m;
  cin >> m;
  for (int i = 0; i < (int)(m); i++) {
    int t;
    int p, q;
    cin >> t;
    if (t == 1) {
      cin >> p >> q;
      cout << s[q - 1] - s[p - 1] + k[p - 1];
    }
    if (t == 2) {
      cin >> p >> q;
      cout << u[q - 1] - u[p - 1] + v[p - 1];
    }
    cout << "\n";
  }
  return 0;
}
