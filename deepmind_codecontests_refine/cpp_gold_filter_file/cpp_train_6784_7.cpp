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
long long power(long long num, long long g) {
  if (g == 0) return 1;
  if (g % 2 == 1) return (num * power((num * num), g / 2));
  return power((num * num), g / 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string r, s;
  cin >> r >> s;
  int l = r.size();
  int m = s.size();
  int one = 0, zero = 0, one1 = 0, zero1 = 0;
  for (int i = 0; i < m; i++) {
    if (s[i] == '1') one++;
  }
  int a[l + 1];
  a[0] = 0;
  for (int i = 1; i <= l; i++) {
    if (r[i - 1] == '0')
      a[i] = a[i - 1];
    else
      a[i] = a[i - 1] + 1;
  }
  int ans = 0;
  for (int i = m; i <= l; i++) {
    int x = a[i] - a[i - m];
    if (abs(x - one) % 2 == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
