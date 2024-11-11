#include <bits/stdc++.h>
using namespace std;
void faster() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
string s, x, t, ans;
long long q, n, a[456789], b[456789], sum, prefa[456789], prefb[456789], k, l,
    r, mx;
bool ok;
void dii() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  k = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] <= 2 * a[i - 1]) {
      k++;
    } else {
      k = 1;
    }
    if (k > mx) {
      mx = k;
    }
  }
  cout << mx;
}
int main() {
  faster();
  q = 1;
  while (q--) {
    dii();
  }
  return 0;
}
