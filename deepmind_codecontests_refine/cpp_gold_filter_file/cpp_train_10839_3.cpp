#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
long long n, k, a, b, c, m, t, pr[N];
bool used[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t) {
    t--;
    cin >> a >> b >> k;
    c = a - b;
    m = c * (k / 2);
    if (k % 2 != 0) m += a;
    cout << m << endl;
  }
}
