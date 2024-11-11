#include <bits/stdc++.h>
using namespace std;
map<char, char> mp;
string a, b;
long long A = 23, B = 1000000007, n, pwr[1000010], hash1[1000010],
          hash2[1000010];
void pre_cal() {
  mp['E'] = 'W';
  mp['W'] = 'E';
  mp['N'] = 'S';
  mp['S'] = 'N';
  pwr[0] = 1;
  for (long long i = 1; i <= 1000000; ++i) {
    pwr[i] = (pwr[i - 1] * A) % B;
  }
}
void rvrs() {
  reverse(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    b[i] = mp[b[i]];
  }
}
int main() {
  pre_cal();
  cin >> n >> a >> b;
  --n;
  rvrs();
  hash1[0] = b[0];
  hash2[0] = a[n - 1];
  for (int i = 1; i < n; ++i) {
    hash1[i] = (hash1[i - 1] * A + b[i]) % B;
    hash2[i] = (hash2[i - 1] + pwr[i] * a[n - 1 - i]) % B;
  }
  bool l = 1;
  for (int i = 0; i < n; ++i) {
    if (hash1[i] == hash2[i]) {
      l = 0;
      break;
    }
  }
  if (l) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
