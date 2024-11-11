#include <bits/stdc++.h>
using namespace std;
const int N = 100000, N_ = N * 27;
int aa[N_];
int main() {
  int n;
  cin >> n;
  int n_ = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int m = s.length();
    int a = 0;
    for (int j = 0; j < m; j++) a ^= 1 << s[j] - 'a';
    aa[n_++] = a;
    for (int h = 0; h < 26; h++) {
      int b = a ^ 1 << h;
      aa[n_++] = b << 1 | 1;
    }
  }
  sort(aa, aa + n_);
  long long ans = 0;
  int a_ = -1, k_ = 0;
  for (int i = 0, j; i < n_; i = j) {
    int a = aa[i];
    j = i + 1;
    while (j < n_ && aa[j] == a) j++;
    int k = j - i;
    if ((a & 1) == 0) {
      ans += (long long)k * (k - 1);
      a_ = a;
      k_ = k;
    } else if ((a ^ 1) == a_)
      ans += (long long)k_ * k;
  }
  ans /= 2;
  cout << ans << '\n';
  return 0;
}
