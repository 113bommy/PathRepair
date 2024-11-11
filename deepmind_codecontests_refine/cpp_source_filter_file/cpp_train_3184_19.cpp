#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long mod2 = 1e9 + 9;
double eps = 1e-9;
int n, m;
const int size = 1e5 + 2;
long long int ts, tf, td, a[size];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> ts >> tf >> td >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  a[n] = -1ll;
  long long int occupied = ts, len = 1ll, point = -1, min_seg = 1e18;
  for (int i = 0; i < n; ++i) {
    if (a[i] == a[i + 1])
      len++;
    else {
      if (occupied < a[i]) {
        cout << occupied << '\n';
        return 0;
      } else if (min_seg > occupied + td - (a[i] - 1ll)) {
        min_seg = occupied + td - (a[i] - 1ll);
        point = a[i] - 1ll;
      }
      occupied += td * len;
      len = 1ll;
      if (occupied + td >= tf) break;
    }
  }
  cout << (occupied + td >= tf ? point : occupied) << '\n';
  cin >> n;
}
