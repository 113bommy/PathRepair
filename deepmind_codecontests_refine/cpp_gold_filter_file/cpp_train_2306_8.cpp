#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(12);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < int(n); i++) cin >> a[i];
  cout << 2 + (a[2] ^ *min_element(a.begin(), a.end())) << endl;
}
