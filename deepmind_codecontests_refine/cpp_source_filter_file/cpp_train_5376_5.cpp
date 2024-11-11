#include <bits/stdc++.h>
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int maxN = 2e5;
const int INF = 1e9 + 7;
const long long LL_INF = 1e18 + 11;
using namespace std;
long long st, n, m;
void file() {
  freopen("numbers.in", "r", stdin);
  freopen("numbers.out", "w", stdout);
}
void boost() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  boost();
  cin >> n >> m;
  st = 1;
  if (n == 1) {
    cout << 0;
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    st *= 2;
    if (m < st) {
      cout << m;
      exit(0);
    }
  }
  if (m == st) {
    cout << 0;
    exit(0);
  }
  cout << m % st;
}
