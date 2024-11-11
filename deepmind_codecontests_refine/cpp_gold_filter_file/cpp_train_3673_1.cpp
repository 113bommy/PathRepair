#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  int zz = 1;
  cin >> zz;
  for (int zzz = 1; zzz <= zz; zzz++) {
    int n;
    cin >> n;
    int l = 0, r = 0;
    string s;
    cin >> s;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
      if (s[i] == '<')
        ++l;
      else if (s[i] == '>')
        ++r;
      else {
        a[i] = 1;
        a[(i + 1) % n] = 1;
      }
    }
    if (l == 0 || r == 0)
      cout << n << endl;
    else {
      int ans = 0;
      for (int i = 0; i < n; i++) ans += a[i];
      cout << ans << endl;
    }
  }
  return 0;
}
