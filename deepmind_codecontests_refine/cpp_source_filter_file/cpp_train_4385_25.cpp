#include <bits/stdc++.h>
using namespace std;
inline void print(int n) {
  if (n == 0) {
    putchar('0');
    putchar('\n');
  } else if (n == -1) {
    putchar('-');
    putchar('1');
    putchar('\n');
  } else {
    char buf[11];
    buf[10] = '\n';
    int i = 9;
    while (n) {
      buf[i--] = n % 10 + '0';
      n /= 10;
    }
    while (buf[i] != '\n') putchar(buf[++i]);
  }
}
int read() {
  int cc = getc(stdin);
  for (; cc < '0' || cc > '9';) cc = getc(stdin);
  int ret = 0;
  for (; cc >= '0' && cc <= '9';) {
    ret = ret * 10 + cc - '0';
    cc = getc(stdin);
  }
  return ret;
}
string read1() {
  int cc = getc(stdin);
  for (; cc < '0' || cc > '9';) cc = getc(stdin);
  string r = "";
  for (; cc >= '0' && cc <= '9';) {
    r += cc;
    cc = getc(stdin);
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int ans = (abs(x - y) * t1);
  int ans1 = 2 * t3 + (abs(x - z) * t2 + abs(x - y) * t2);
  if (ans1 <= ans)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
