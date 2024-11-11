#include <bits/stdc++.h>
using namespace std;
const int N = 2000210;
inline int scan() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
inline long long int gcd(long long int a, long long int b) {
  long long int t;
  while (b) {
    a = a % b;
    t = a;
    a = b;
    b = t;
  }
  return a;
}
int main() {
  string s;
  bool lasthash = 0;
  while (getline(cin, s)) {
    long long int i;
    for (i = 0; i < (signed)s.size() && s[i] == ' '; i++)
      ;
    if (s[i] == '#') {
      if (lasthash) cout << endl;
      cout << s << endl;
      lasthash = 1;
    } else {
      for (i = 0; i < (signed)s.size(); i++)
        if (s[i] != ' ') cout << s[i];
      lasthash = 1;
    }
  }
  if (lasthash) cout << endl;
  return 0;
}
