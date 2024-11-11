#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio();
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  long long n, a = 4, b = 5, c = 6, d = 3, e = 2, f = 1, i;
  char s;
  long long len = str.size();
  s = str[len - 1];
  n = 0;
  for (i = 0; i < len - 1; i++) {
    n = (10 * n) + (str[i] - 48);
  }
  long long ans, val = (n % 2);
  if (n % 2 == 0) {
    if (s == 'a') {
      val = a + 7;
    } else if (s == 'b') {
      val = b + 7;
    } else if (s == 'c') {
      val = c + 7;
    } else if (s == 'd') {
      val = d + 7;
    } else if (s == 'e') {
      val = e + 7;
    } else if (s == 'f') {
      val = f + 7;
    }
  } else {
    if (s == 'a') {
      val = a;
    } else if (s == 'b') {
      val = b;
    } else if (s == 'c') {
      val = c;
    } else if (s == 'd') {
      val = d;
    } else if (s == 'e') {
      val = e;
    } else if (s == 'f') {
      val = f;
    }
  }
  ans = (16 * ceil((n - 1) / 4)) + val;
  cout << ans << "\n";
}
