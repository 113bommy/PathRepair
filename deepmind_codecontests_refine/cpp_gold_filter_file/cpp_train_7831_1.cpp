#include <bits/stdc++.h>
using namespace std;
void Sieve(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int c1 = 0, c0 = 0;
    string s;
    cin >> s;
    fflush(stdin);
    int len = s.size();
    for (int i = 0; i < len; i++) {
      if (s[i] == '1')
        c1++;
      else
        c0++;
    }
    if (c1 == 0 || c0 == 0)
      cout << s << endl;
    else {
      for (int i = 0; i < len; i++) cout << 10;
      cout << endl;
    }
  }
  return 0;
}
