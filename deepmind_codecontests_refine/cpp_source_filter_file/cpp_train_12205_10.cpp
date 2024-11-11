#include <bits/stdc++.h>
using namespace std;
int howfar(const std::string& s) {
  const int N = s.length();
  int r(0);
  int d(1);
  for (int i = 0; i != N; ++i) {
    switch (s[i]) {
      case 'F':
        r += d;
        break;
      case 'T':
        d = -d;
        break;
      default:
        assert(0);
    }
  }
  return r;
}
char invert(char c) { return c == 'T' ? 'F' : 'T'; }
int solve(const std::string& s, int n) {
  const int N = s.length();
  if (n > 0 && n % 2 == 0) {
    int rm(-10000);
    std::string sm;
    std::string s2 = s;
    for (int i1 = 0; i1 != N; ++i1) {
      for (int i2 = 0; i2 != N; ++i2) {
        s2[i1] = invert(s2[i1]);
        s2[i2] = invert(s2[i2]);
        const int r2 = howfar(s2);
        if (r2 > rm) {
          rm = r2;
          sm = s2;
        }
        s2[i2] = invert(s2[i2]);
        s2[i1] = invert(s2[i1]);
      }
    }
    return solve(sm, n - 2);
  } else if (n > 0) {
    int rm(-10000);
    std::string sm = s;
    for (int i = 0; i != N; ++i) {
      std::string s2 = s;
      s2[i] = invert(s2[i]);
      const int r = howfar(s2);
      if (r > rm) {
        rm = r;
        sm = s2;
      }
    }
    return solve(sm, n - 1);
  }
  return howfar(s);
}
int main(int argc, char* argv[]) {
  std::string s;
  cin >> s;
  int n;
  cin >> n;
  cout << solve(s, n) << endl;
  return 0;
}
