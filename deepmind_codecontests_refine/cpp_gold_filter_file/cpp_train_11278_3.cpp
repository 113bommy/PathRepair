#include <bits/stdc++.h>
using namespace std;
int ms[100001];
int main() {
  memset(ms, 0, sizeof ms);
  int a, b, m, u;
  cin >> a >> b >> m >> u;
  u = u % m;
  for (int i = 0;; i++) {
    if (ms[u] == 0)
      ms[u] = i;
    else {
      cout << i - ms[u];
      break;
    }
    u = (a * u % m + b % m) % m;
  }
}
