#include <bits/stdc++.h>
using namespace std;
long long s[111111], bb[111111];
long long y, w;
long long n, m, k;
long long solve(int op) {
  int pos, pos2, op1, tmp;
  long long as = 0;
  pos = bb[op];
  pos2 = pos - 1;
  op1 = s[pos];
  if (pos <= k)
    as = 1;
  else {
    as = (pos - 1) / k + 1;
  }
  if (pos != 1) {
    tmp = s[pos], s[pos] = s[pos2], s[pos2] = tmp;
    tmp = bb[op], bb[op] = bb[op1], bb[op1] = tmp;
  }
  return as;
}
int main() {
  y = 0;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    bb[s[i]] = i;
  }
  while (m--) {
    int as;
    cin >> as;
    y += solve(as);
  }
  cout << y << endl;
}
