#include <bits/stdc++.h>
using namespace std;
template <class T>
void rd(T &k) {
  char c = getchar();
  int f = 1;
  k = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f *= -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    k = k * 10 + c - '0';
    c = getchar();
  }
  k *= f;
}
const int N = 60;
long long n, m, k, s, t, sum, tot, a[100005];
queue<long long> q[60];
int main() {
  rd(n);
  for (register int i = 1; i <= n; ++i) {
    rd(k);
    for (register int j = 59; j >= 0; --j)
      if (k & (1ll << j)) {
        q[j].push(k);
        break;
      }
  }
  for (register int i = 1; i <= n; ++i) {
    int bo = 0;
    for (register int j = 0; j <= 59; ++j)
      if (!(sum & (1ll << j)) && !q[j].empty()) {
        a[++tot] = q[j].front();
        q[j].pop();
        sum ^= a[tot];
        bo = 1;
        break;
      }
    if (!bo) {
      return cout << "No", 0;
    }
  }
  cout << "Yes\n";
  for (register int i = 1; i <= n; ++i) cout << a[i] << ' ';
}
