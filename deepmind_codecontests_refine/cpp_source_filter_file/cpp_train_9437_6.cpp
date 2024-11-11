#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void write(T x) {
  int i = 20;
  char buf[21];
  buf[20] = '\n';
  do {
    buf[--i] = x % 10 + '0';
    x /= 10;
  } while (x);
  do putchar(buf[i]);
  while (buf[i++] != '\n');
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
int main() {
  string s;
  set<char> cs;
  cin >> s;
  if ((long long int)s.size() < 4) {
    cout << "No\n";
    return 0;
  }
  for (auto c : s) cs.insert(c);
  if ((long long int)cs.size() > 4) {
    cout << "No\n";
    return 0;
  }
  if ((long long int)cs.size() == 3 || (long long int)cs.size() == 4) {
    cout << "Yes\n";
    return 0;
  }
  if ((long long int)s.size() == 1) {
    cout << "No\n";
    return 0;
  }
  sort(s.begin(), s.end());
  if (s[0] == s[1] &&
      s[(long long int)s.size() - 1] == s[(long long int)s.size() - 2])
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
