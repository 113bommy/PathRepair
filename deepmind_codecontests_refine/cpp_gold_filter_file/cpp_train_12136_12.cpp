#include <bits/stdc++.h>
int main() {
  using namespace std;
  long n;
  cin >> n;
  char s[n], s1[n];
  cin >> s;
  if (n % 2 == 0) {
    long h = 1;
    s1[(n - 1) / 2] = s[0];
    for (long i = (n - 1) / 2 + 1; i < n; i++) {
      s1[i] = s[h];
      h += 2;
    }
    h = 2;
    for (long i = (n - 1) / 2 - 1; i >= 0; i--) {
      s1[i] = s[h];
      h += 2;
    }
  } else {
    s1[(n - 1) / 2] = s[0];
    long h = 2;
    for (long i = (n - 1) / 2 + 1; i < n; i++) {
      s1[i] = s[h];
      h += 2;
    }
    h = 1;
    for (long i = (n - 1) / 2 - 1; i >= 0; i--) {
      s1[i] = s[h];
      h += 2;
    }
  }
  s1[n] = '\0';
  cout << s1 << endl;
}
