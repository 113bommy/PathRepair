#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> fuck;
  int ans = 0;
  for (int k = 0; k < n; k++) {
    string s;
    cin >> s;
    int d = 0;
    for (int j = 0; j < s.size(); j++) {
      char c = s[j] - 'a';
      d ^= (1 << c);
    }
    if (fuck.count(d)) ans += fuck[d];
    for (int i = 26; i > 0; i--) {
      d ^= (1 << i);
      if (fuck.count(d)) ans += fuck[d];
      d ^= (1 << i);
    }
    fuck[d]++;
  }
  cout << ans;
}
