#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
  string s;
  int n, k;
  cin >> n >> k >> s;
  s = s + '8';
  vector<int> pr(s.size() + 1, 0), pp(s.size() + 1, 0);
  for (int i = s.size() - 2; i >= 0; --i) {
    if (s[i] == 'N') pp[i] = pp[i + 1] + 1;
    if (s[i] != 'Y') pr[i] = pr[i + 1] + 1;
  }
  bool ok = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (pr[i] >= k && s[i + k] != 'N') {
      if (i > 0 && s[i - 1] != 'N' || i == 0) {
        ok = 1;
      }
    }
  }
  for (int i = 0; i < s.size() - 1; i++) {
    if (pp[i] > k) {
      cout << "NO";
      exit(0);
    }
  }
  if (ok)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
