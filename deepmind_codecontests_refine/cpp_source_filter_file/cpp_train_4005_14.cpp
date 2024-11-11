#include <bits/stdc++.h>
using namespace std;
int64_t bits(int64_t st, int64_t en) {
  int64_t n = st, index = -1, res;
  bool check = true;
  while (n >= st && n <= en) {
    if (check == true) res = n;
    index++;
    if (n & (1 << index))
      check = false;
    else
      check = true, n = n + (1 << index);
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  int64_t l[n + 1], r[n + 1];
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  for (int i = 1; i <= n; i++) cout << bits(l[i], r[i]) << endl;
  return 0;
}
