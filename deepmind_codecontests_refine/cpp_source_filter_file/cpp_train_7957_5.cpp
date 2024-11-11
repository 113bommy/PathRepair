#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int z = s.length(), sum = 0, q, m = 0, r = 0;
  int k;
  cin >> k;
  int ar[z], br[z];
  int w[26];
  for (int i = 0; i < 26; i++) {
    cin >> w[i];
    m = max(m, w[i]);
  }
  for (int i = 0; i <= z; i++) {
    q = (s[i] - 'a');
    ar[i] = (i + 1) * w[q];
  }
  r = z * m + k * (m) * (m) * (k + 1) / 2;
  for (int i = 0; i < z; i++) {
    sum = sum + ar[i];
  }
  cout << sum + r;
}
