#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int const N = 100 * 1000 + 16;
int const M = 1000 * 1000 * 1000 + 7;
int const lim = 2 * 1000 * 1000 + 16;
bool c[lim];
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    c[a[i]] = true;
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    c[b[i]] = true;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int x = (a[i] ^ b[j]);
      if (x <= lim && c[x]) cnt++;
    }
  }
  cout << ((cnt & 1) ? "Koyomi" : "Karen");
}
