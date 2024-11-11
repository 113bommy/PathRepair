#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int t;
long long n;
const long long QAQ = 1e14;
int main() {
  t = read();
  while (t--) {
    long long sp;
    cin >> sp >> n;
    if (n == 0) {
      cout << sp << endl;
      continue;
    }
    long long tmp = (n - 1) / 4;
    tmp *= -4;
    if (n == 1) {
      if ((sp + QAQ) % 2 == 0) {
        cout << -1 << endl;
        continue;
      }
      if ((sp + QAQ) % 2 == 1) {
        cout << 1 << endl;
        continue;
      }
    }
    tmp--;
    int opt = (n - 1) % 4;
    if (opt == 1) tmp += n;
    if (opt == 2) tmp += n + n - 1;
    if (opt == 3) tmp += n - 1 + n - 2 - n;
    if ((sp + QAQ) % 2 == 1) tmp = -tmp;
    tmp += sp;
    cout << tmp << endl;
  }
}
