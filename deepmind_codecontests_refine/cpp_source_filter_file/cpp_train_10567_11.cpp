#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  while (n--) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    l--;
    r--;
    if (l == r) continue;
    k %= (r - l);
    s = s.substr(0, l) + s.substr(r - k + 1, k) + s.substr(l, r - l - k + 1) +
        s.substr(r + 1, s.size());
  }
  cout << s;
  return 0;
}
