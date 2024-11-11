#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  string a, b, c;
  for (long long int i = 0; i < 30005; i++) a += "RGB";
  for (long long int i = 0; i < 300005; i++) b += "GBR";
  for (long long int i = 0; i < 300005; i++) c += "BRG";
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long int mn = (long long int)1e18;
    long long int mn_a = 0, mn_b = 0, mn_c = 0;
    for (long long int i = 0; i < k; i++) {
      if (s[i] != a[i]) mn_a++;
      if (s[i] != b[i]) mn_b++;
      if (s[i] != c[i]) mn_c++;
    }
    long long int p, q, x;
    mn = min(mn, mn_a);
    mn = min(mn, mn_b);
    mn = min(mn, mn_c);
    for (long long int i = 1; i <= (n - k); i++) {
      p = mn_a;
      if (s[i - 1] != a[0]) p--;
      if (s[i + k - 1] != b[k - 1]) p++;
      q = mn_b;
      if (s[i - 1] != b[0]) q--;
      if (s[i + k - 1] != c[k - 1]) q++;
      x = mn_c;
      if (s[i - 1] != c[0]) x--;
      if (s[i + k - 1] != a[k - 1]) x++;
      mn_a = x;
      mn_b = p;
      mn_c = q;
      mn = min(mn, mn_a);
      mn = min(mn, mn_b);
      mn = min(mn, mn_c);
    }
    cout << mn << endl;
  }
  return 0;
}
