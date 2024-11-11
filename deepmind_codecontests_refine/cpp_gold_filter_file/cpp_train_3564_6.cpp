#include <bits/stdc++.h>
const int INF = 1 << 30;
const long long LINF = 1ll << 60;
using namespace std;
const int N = 100010;
int a[N];
int b[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int qq;
  cin >> qq;
  while (qq--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool can = true;
    bool c1, c_1;
    c1 = c_1 = false;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (a[i] != b[i]) {
        if (b[i] < a[i] && !c_1) can = false;
        if (b[i] > a[i] && !c1) can = false;
      }
      if (a[i] == 1) c1 = true;
      if (a[i] == -1) c_1 = true;
    }
    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
