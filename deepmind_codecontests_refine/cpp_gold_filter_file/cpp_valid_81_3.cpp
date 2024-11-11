#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<long long> plus, minus;
  plus.push_back(0);
  minus.push_back(0);
  for (long long i = 0; i < n; i++) {
    if (i % 2) {
      if (s[i] == '+') {
        s[i] = '-';
      } else {
        s[i] = '+';
      }
    }
  }
  long long pluscount = 0, minuscount = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '+') {
      pluscount++;
    } else {
      minuscount++;
    }
    plus.push_back(pluscount);
    minus.push_back(minuscount);
  }
  while (q--) {
    long long l, r;
    cin >> l >> r;
    long long p = plus[r] - plus[l - 1];
    long long m = minus[r] - minus[l - 1];
    if (p == m) {
      cout << 0 << endl;
    } else if ((p + m) % 2 == 0) {
      cout << 2 << endl;
    } else {
      cout << 1 << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
