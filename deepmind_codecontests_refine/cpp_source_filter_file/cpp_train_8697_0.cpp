#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, inf = 1e9;
bool stol1[MAXN];
int kras[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, t = 2;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (x % 2 == 0) t = (t + 1) % 2;
    if (t == 0) ++t;
    cout << t << '\n';
  }
}
