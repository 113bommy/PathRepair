#include <bits/stdc++.h>
using namespace std;
long long const MOD = 1e9 + 7;
long long const N = 1e3 + 10;
long long ara[N + 1];
long long bra[N + 1];
int main() {
  (ios_base::sync_with_stdio(false), cin.tie(NULL));
  long long n, m, q;
  cin >> n >> m >> q;
  string str, s;
  cin >> str >> s;
  for (long long i = 0; i < n - m + 1; i++) {
    long long j = 0, pre = i;
    while (j < m) {
      if (str[i] == s[j]) {
        i++;
        j++;
      } else
        break;
    }
    if (j == m) {
      bra[pre + 1]++;
      i--;
      bra[i]--;
      ara[pre + 1]++;
    }
    i = pre;
  }
  for (long long i = 1; i <= n + 10; i++) {
    ara[i] += ara[i - 1];
    bra[i] += bra[i - 1];
  }
  while (q--) {
    long long a, b;
    cin >> a >> b;
    b = b - m + 1;
    cout << max(0ll, ara[max(b, 0ll)] - ara[a - 1]) << endl;
  }
}
