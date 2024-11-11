#include <bits/stdc++.h>
using namespace std;
int pl[100001];
int main() {
  int n, a, b, r, c = 0;
  cin >> a >> b >> n >> r;
  memset(pl, -1, sizeof pl);
  while (pl[r] == -1) {
    pl[r] = c++;
    r = ((a * r) + b) % n;
  }
  cout << c - pl[r] + 1 << endl;
  return 0;
}
