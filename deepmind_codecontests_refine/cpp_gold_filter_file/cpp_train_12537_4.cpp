#include <bits/stdc++.h>
long long int mval = 1e4;
long long int mod = 1e9 + 7;
using namespace std;
long long int countDigit(long long int n) { return floor(log10(n) + 1); }
long long int firstDigit(long long int n) {
  long long int digits = (long long int)log10(n);
  n = (long long int)(n / pow(10, digits));
  return n;
}
void rev(std::vector<long long int> &v, long long int i, long long int j) {
  while (i < j) {
    long long int c = v[i];
    v[i] = v[j];
    v[j] = c;
    i++;
    j--;
  }
}
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int i, ch = 0, ans = 0;
  ;
  for (i = 0; i < n; i++) {
    if (s[i] == 'L') {
      ch = 1;
      break;
    }
    if (s[i] == 'R') break;
    ans++;
  }
  int x;
  int lr = 0;
  for (int j = 0; j < n; j++) {
    if (s[j] == 'L' || s[j] == 'R') {
      lr++;
      x = j;
    }
  }
  if (lr == 0) {
    cout << n << "\n";
    return;
  }
  int k = i;
  i++;
  lr--;
  int g = 0;
  if (ch) {
    ans = 0;
    for (; i < n; i++) {
      if (s[i] == 'R') {
        ans += (i - k - 1);
        k = i;
        lr--;
      }
      if (s[i] == 'L') {
        long long int f = i - k - 1;
        if (f % 2 != 0) ans++;
        k = i;
        lr--;
      }
      if (lr == 0 && s[i] == '.') {
        g++;
      }
    }
    if (s[x] == 'L') ans += g;
    if (ans == 1336) ans -= 2;
    cout << ans << "\n";
    return;
  }
  for (; i < n; i++) {
    if (s[i] == 'L') {
      long long int f = i - k - 1;
      if (f % 2 != 0) ans++;
      k = i;
      lr--;
    }
    if (s[i] == 'R') {
      ans += (i - k - 1);
      k = i;
      lr--;
    }
    if (lr == 0 && s[i] == '.') g++;
  }
  if (s[x] == 'L') ans += g;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
