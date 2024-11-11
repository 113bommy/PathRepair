#include <bits/stdc++.h>
using namespace std;
long long Ans;
long long pos = 0;
long long s[55];
long long a, b;
void init() {
  Ans = 0;
  memset(s, 0, sizeof(s));
  pos = 0;
  while (a) {
    s[++pos] = a % 10;
    a /= 10;
  }
}
bool Check() {
  long long res = 0;
  for (long long i = 0; i < 20; i++) {
    res += s[i];
    if (res > b) return false;
  }
  return true;
}
long long Copy;
void Print() {
  long long r;
  if (s[pos + 1] == 0)
    r = pos;
  else
    r = pos + 1;
  long long sum = 0;
  for (long long i = r; i >= 1; i--) sum = sum * 10 + s[i];
  cout << sum - Copy << endl;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    Copy = a;
    init();
    long long nxt = 1;
    for (long long i = 1; i <= pos; i++) {
      if (Check()) {
        Print();
        break;
      }
      if (s[i] == 0) {
        continue;
      }
      if (i == pos) {
        s[i] = 0;
        s[i + 1] = 1;
        Print();
        break;
      }
      s[i] = 0;
      s[i + 1]++;
      long long p = i + 1;
      while (p <= pos && s[p] == 10) {
        s[p] = 0;
        s[p + 1]++;
        p++;
      }
      if (p == pos) {
        if (Check())
          Print();
        else {
          s[p] = 0;
          s[p + 1] = 1;
          Print();
        }
        break;
      }
      nxt *= 10;
    }
  }
  return 0;
}
