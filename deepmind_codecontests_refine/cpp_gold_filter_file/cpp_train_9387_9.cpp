#include <bits/stdc++.h>
using namespace std;
const int max_n = 1000005, log_n = 32, max_m = 111, mod = 1000000007,
          inf = 1011111111, p = 997, sz = 100;
int n, p_f[max_n * 2], z_f[max_n * 2];
string a, b;
void get_p_f(const string s, int p_f[]) {
  int n = s.length();
  int k = 0;
  for (int i = 1; i < n; ++i) {
    while (k && s[k] != s[i]) {
      k = p_f[k - 1];
    }
    if (s[k] == s[i]) {
      ++k;
    }
    p_f[i] = k;
  }
}
void get_z_f(const string s, int z_f[]) {
  int n = s.length();
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) {
      z_f[i] = min(z_f[i - l], r - i + 1);
    }
    while (i + z_f[i] < n && s[z_f[i]] == s[i + z_f[i]]) {
      z_f[i]++;
    }
    if (z_f[i] + i - 1 > r) {
      r = z_f[i] + i - 1;
      l = i;
    }
  }
}
int main() {
  getline(cin, a);
  getline(cin, b);
  n = a.length();
  if (n != b.length()) {
    cout << "-1 -1\n";
    return 0;
  }
  reverse(a.begin(), a.end());
  get_p_f(a + "#" + b, p_f);
  reverse(a.begin(), a.end());
  get_z_f(b + "#" + a, z_f);
  reverse(b.begin(), b.end());
  int l = -1, r = -1;
  for (int i = 1; i < n && a[i - 1] == b[i - 1]; ++i) {
    if (z_f[i + n + 1] && p_f[n * 2 - i] &&
        z_f[i + n + 1] + p_f[n * 2 - i] >= n - i) {
      l = i - 1;
      r = max(l + 1, n - p_f[n * 2 - i]);
    }
  }
  cout << l << " " << r << endl;
  return 0;
}
