#include <bits/stdc++.h>
using namespace std;
const int MAXLEN = 1e5 + 3;
int lev(long long i) { return log2(i & -i); }
long long u(long long i) {
  int l = lev(i);
  if (l == 0) {
    if ((i + 1) % 4 == 0) return i - 1;
    return i + 1;
  }
  return u(i / pow(2, l)) * pow(2, l);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, q, root, st;
  cin >> n >> q;
  root = (n + 1) / 2;
  char data[MAXLEN];
  int len;
  while (q--) {
    cin >> st >> data;
    len = strlen(data);
    for (int i = 0; i < len; ++i) {
      if (data[i] == 'U') {
        if (u(st) <= root) st = u(st);
      } else if (data[i] == 'L') {
        if (lev(st) != 0) st = st - pow(2, lev(st) - 1);
      } else {
        if (lev(st) != 0) st = st + pow(2, lev(st) - 1);
      }
    }
    cout << st << endl;
  }
  return 0;
}
