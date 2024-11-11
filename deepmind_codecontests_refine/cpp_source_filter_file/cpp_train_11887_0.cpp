#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int sz = 1 << 6;
const int inf = 2e9;
const int mod = 1e9 + 7;
const double pi = acos(-1);
long long n, m;
template <class T>
inline void read(T &x) {
  char c;
  x = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') x = -1;
  T res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
  x *= res;
}
int main() {
  read(n);
  if (n & 1 == 0)
    cout << "NO\n";
  else {
    cout << "YES\n";
    queue<int> q1, q2;
    for (int i = 1; i <= n; i++) {
      if (i & 1) {
        q1.push(2 * i - 1);
        q2.push(2 * i);
      } else {
        q2.push(2 * i - 1);
        q1.push(2 * i);
      }
    }
    while (q1.size()) {
      cout << q1.front() << ' ';
      q1.pop();
    }
    while (q2.size()) {
      cout << q2.front();
      if (q2.size() > 1) cout << ' ';
      q2.pop();
    }
    cout << endl;
  }
  return 0;
}
