#include <bits/stdc++.h>
long long int mod = 1000000000 + 7;
long long int inf = (long long int)(5e18);
using namespace std;
mt19937 unlucko(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> a(n, -1);
  int goend = n;
  while (m--) {
    int x;
    cin >> x;
    if (x <= c / 2) {
      int i = 0;
      while (a[i] != -1 && a[i] <= x) {
        ++i;
      }
      cout << i + 1 << endl;
      if (a[i] == -1) --goend;
      a[i] = x;
    } else {
      int i = n - 1;
      while (a[i] != -1 && a[i] >= x) {
        i--;
      }
      if (a[i] == -1) goend--;
      cout << i + 1 << endl;
      a[i] = x;
    }
    if (!goend) return 0;
  }
}
