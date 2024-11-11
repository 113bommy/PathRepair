#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  fast();
  long int n;
  cin >> n;
  long int a[n], g[n];
  for (long int i = 0; i < n; i++) cin >> a[i] >> g[i];
  int f = 1;
  long long int as = 0;
  as = accumulate(a, a + n, as);
  long long int gs = 0, ts = 0;
  gs = accumulate(g, g + n, gs);
  string s1;
  for (long int i = 0; i < n; i++) {
    if (ts + a[i] <= 500) {
      s1.push_back('A');
      ts += a[i];
    } else {
      s1.push_back('G');
      ts -= a[i];
    }
  }
  cout << s1 << "\n";
  return 0;
}
