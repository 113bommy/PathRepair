#include <bits/stdc++.h>
using namespace std;
int i, j, k, cnt;
bool v[100050] = {false};
int r[100050];
int main() {
  int a, b, m, r0;
  cin >> a >> b >> m >> r0;
  for (i = 1; i < m + 1; i++) {
    r0 = (a * r0 + b) % m;
    if (v[r0]) {
      cout << i - r[r0] << endl;
      exit(0);
    }
    r[r0] = i;
    v[r0] = true;
  }
  return ~~(0 ^ 0 ^ 0);
}
