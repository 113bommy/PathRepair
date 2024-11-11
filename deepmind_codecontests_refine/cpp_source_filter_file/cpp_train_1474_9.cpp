#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
long long n, i, j, k, m;
long long dem = 0, tong = 0, x, y, z, l, r, dem1 = 0, tong1 = 0;
char k1, k2;
long long a[maxn], b[maxn], c[maxn], h[maxn], d[maxn], e[maxn];
char s[maxn], s1[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (i = 0; i <= 1e6; i++) {
    if (b[i] == 1) {
      dem++;
      c[dem] = i;
    } else if (b[i] == 2) {
      dem++;
      c[dem] = i;
      tong++;
      d[tong] = i;
    } else if (b[i] == 3) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES"
       << "\n";
  cout << tong << "\n";
  for (i = 1; i <= tong; i++) cout << d[i] << " ";
  cout << "\n";
  cout << dem << "\n";
  for (i = dem; i >= 1; i--) cout << c[i] << " ";
}
