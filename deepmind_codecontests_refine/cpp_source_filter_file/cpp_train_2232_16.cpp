#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b, c, d;
  string s;
  cin >> a >> b >> c >> d >> s;
  int sum = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      sum += a;
    } else if (s[i] == '2') {
      sum += b;
    } else if (s[i] == '3') {
      sum += b;
    } else {
      sum += d;
    }
  }
  cout << sum;
}
