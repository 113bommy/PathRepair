#include <bits/stdc++.h>
using namespace std;
bool is_possible(string s, long long int a, long long int b, long long int p,
                 long long int mid) {
  long long int spent = 0;
  long long int i = mid;
  while (i < s.length()) {
    long long int source = s[i];
    if (source == 'A') {
      spent += a;
    } else
      spent += b;
    if (spent > p) return false;
    i++;
    while (i <= s.length() && s[i] == source) i++;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t, a, b, p;
  cin >> t;
  while (t--) {
    cin >> a >> b >> p;
    string path;
    cin >> path;
    long long int s = 0, e = path.length() - 1;
    long long int ans, mid;
    while (s <= e) {
      mid = (s + e) / 2;
      if (is_possible(path, a, b, p, mid)) {
        e = mid - 1;
        ans = mid;
      } else
        s = mid + 1;
    }
    cout << ans + 1 << "\n";
  }
}
