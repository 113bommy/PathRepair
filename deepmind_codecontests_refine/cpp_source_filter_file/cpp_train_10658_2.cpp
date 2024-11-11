#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
ll mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  ld mx = 0.0;
  ld count = 0.0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ld a;
    cin >> a;
    count += a;
    mx = max(mx, count / i);
  }
  cout << mx << endl;
}
