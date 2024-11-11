#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string a, b;
  cin >> a;
  cin >> b;
  int ans = 0;
  for (int i = 0; i < n / 2; ++i) {
    map<char, int> c;
    c[a[i]]++;
    c[a[n - i - 1]]++;
    c[b[i]]++;
    c[b[n - i - 1]]++;
    if ((int)c.size() == 4) {
      ans += 2;
    } else if ((int)c.size() == 3) {
      ans += 1 + (a[i] == a[n - i + 1]);
    } else if ((int)c.size() == 2) {
      ans += (c[a[i]] != 2);
    }
  }
  if (n % 2 == 1 and a[n / 2] != b[n / 2]) ans++;
  cout << ans << endl;
  return 0;
}
