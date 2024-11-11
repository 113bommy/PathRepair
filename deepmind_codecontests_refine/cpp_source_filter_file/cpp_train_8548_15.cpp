#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
string s, p;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  cin >> s >> p;
  long long carry;
  long long t = -1;
  for (long long i = 0; i < n; i++) {
    if (s[i] != p[i]) {
      t = i;
      break;
    }
  }
  if (t == -1) {
    cout << n << "\n";
    return 0;
  }
  t = n - t;
  if (t < 30) {
    long long a = 0, b = 0;
    for (long long i = n - t; i < n; i++) {
      a += (s[i] - 'a') * pow(2, n - 1 - i);
      b += (p[i] - 'a') * pow(2, n - 1 - i);
    }
    k = min(k, b - a + 1);
  }
  long long prev = 0, count = 1;
  long long ans = 0;
  long long temp;
  for (long long i = 0; i < n; i++) {
    if (prev == 0 && s[i] == p[i]) {
      ans++;
    }
    if (prev == 0 && s[i] != p[i]) {
      temp = 2 * count;
      ans += min((long long)k, temp);
      if (count < k) count = temp;
      prev = 1;
    } else if (prev != 0) {
      temp = 2 * count;
      if (s[i] == 'b') temp--;
      if (p[i] == 'a') temp--;
      ans += min((long long)k, temp);
      if (count < k) count = temp;
    }
  }
  cout << ans;
}
