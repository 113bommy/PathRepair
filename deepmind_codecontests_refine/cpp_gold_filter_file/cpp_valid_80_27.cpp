#include <bits/stdc++.h>
using namespace std;
void print(int a, int b, int c, int d) {
  a++;
  b++;
  c++;
  d++;
  cout << a << " " << b << " " << c << " " << d;
  cout << endl;
}
void solve() {
  string s;
  int n;
  cin >> n;
  cin >> s;
  int zero = -1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      zero = i;
    }
  }
  if (zero == -1) {
    print(0, n - 2, 1, n - 1);
  } else if (zero >= n / 2) {
    print(0, zero, 0, zero - 1);
  } else {
    print(zero, n - 1, zero + 1, n - 1);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
