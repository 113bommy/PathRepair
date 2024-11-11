#include <bits/stdc++.h>
using namespace std;
char p[100010];
int n, co, z[100010];
int main() {
  cin >> (p + 1);
  n = strlen((p + 1));
  for (int i = 1; i <= n; ++i) z[i] = z[i - 1] + int(p[i] == '0');
  for (int i = n; i > 0; --i) {
    int now = 0;
    while (p[i] == '0') now++, i--;
    ++co;
    if ((i - 1) > now + 1) {
      continue;
    }
    if ((i - 1) < now + 1) break;
    if (z[i - 1] < now && p[1] >= p[i]) {
      continue;
    }
    if (p[1] > p[i]) {
      continue;
    } else {
      break;
    }
  }
  cout << co << '\n';
}
