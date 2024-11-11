#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9 + 5;
const int NMAX = 1e5 + 5;
map<string, int> H;
string a[NMAX];
int b[NMAX];
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> H[a[i]];
  for (int i = 1; i <= k; i++) {
    int p;
    cin >> p;
    b[i] = MAX;
    for (int j = 1; j <= p; j++) {
      int t;
      cin >> t;
      b[i] = min(b[i], H[a[t]]);
      H[a[t]] = i;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    string d;
    cin >> d;
    ans += 1LL * b[H[d]];
  }
  cout << ans;
}
