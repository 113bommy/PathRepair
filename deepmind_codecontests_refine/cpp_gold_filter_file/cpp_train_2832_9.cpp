#include <bits/stdc++.h>
using namespace std;
long long int bubsort(string a) {
  long long int cnt = 0, n = a.size();
  for (long long int i = 0; i <= n - 1; i++) {
    for (long long int j = 0; j <= n - 1; j++) {
      if (a[j] > a[j + 1]) {
        cnt++;
        swap(a[j], a[j + 1]);
      }
    }
  }
  return cnt;
}
int main() {
  long long int q;
  cin >> q;
  while (q--) {
    long long int n, i, j, k, l, o, p;
    cin >> n;
    string s, t;
    cin >> s >> t;
    long long int c[27] = {0}, mx = 0;
    for (long long int i = 0; i <= n - 1; i++) c[s[i] - 'a']++;
    for (long long int i = 0; i <= 26; i++) mx = max(mx, c[i]);
    for (long long int i = 0; i <= n - 1; i++) c[t[i] - 'a']--;
    long long int chck = 0;
    for (long long int i = 0; i <= 26; i++) chck += (c[i] != 0);
    if (!chck) {
      if (mx > 1)
        cout << "YES\n";
      else if ((bubsort(s) % 2) == (bubsort(t) % 2))
        cout << "YES\n";
      else
        cout << "NO\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
