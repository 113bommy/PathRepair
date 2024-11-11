#include <bits/stdc++.h>
using namespace std;
const long long LINF = (long long)1e18 + 47;
const int INF = (int)1e9 + 47;
const int MOD = (int)1e9 + 7;
const int modulo = 998244353;
const int nax = (int)1e5 + 47;
const double EPS = 1e-10;
const int K = 26;
const double PI = acos(-1);
clock_t time_start = clock();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  for (int i = (1); i < (50); i++) {
    if ((((1LL << i) - 1) << 1LL) % ((1LL << i) - 1) != 0) {
      cout << "BAD\n";
    }
  }
  int tt;
  cin >> tt;
  for (int test = (1); test < (tt + 1); test++) {
    int n;
    cin >> n;
    string second;
    cin >> second;
    bool all_one = true;
    for (int i = (0); i < ((int)second.size()); i++)
      all_one &= (second[i] == '1');
    if (all_one) {
      cout << 2 << ' ' << n << ' ' << 1 << ' ' << n - 1 << '\n';
      continue;
    }
    for (int i = (0); i < (((int)second.size() + 1) / 2); i++) {
      if (second[i] == '0') {
        cout << i + 1 << ' ' << i + 1 + (int)second.size() / 2 << ' ' << i + 2
             << ' ' << i + 2 + (int)second.size() / 2 - 1 << '\n';
        goto nxt;
      }
    }
    for (int i = (0); i < ((int)second.size()); i++) {
      if (second[i] == '0') {
        cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << '\n';
        goto nxt;
      }
    }
  nxt:;
  }
}
