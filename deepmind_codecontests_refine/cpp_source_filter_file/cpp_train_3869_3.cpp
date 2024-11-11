#include <bits/stdc++.h>
using namespace std;
long long a, i, n, flag, otvet, bmax, b[100001] = {0}, c[100001] = {0};
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    flag = 0;
    cin >> a;
    c[b[a]]--;
    b[a]++;
    c[b[a]]++;
    bmax = max(bmax, b[a]);
    if (c[1] == i) flag = 1;
    if (c[i] == 1) flag = 1;
    if (c[1] == 1 && bmax * c[b[bmax]] == i - 1) flag = 1;
    if (c[bmax] == 1 && (bmax - 1) * c[bmax - 1] == i - bmax) flag = 1;
    if (flag) otvet = i;
  }
  cout << otvet << endl;
  return 0;
}
