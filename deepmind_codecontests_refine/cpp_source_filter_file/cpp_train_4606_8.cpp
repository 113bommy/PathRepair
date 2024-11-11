#include <bits/stdc++.h>
using namespace std;
inline int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
int f(int n) {
  const vector<int> perm = {4, 1, 3, 0, 2, 5};
  int res = 0;
  for (int i = 0; i < 6; ++i) {
    res |= !!(n & (1 << i)) << perm[i];
  }
  return res;
}
int main() {
  cout << f(nxt()) << "\n";
  return 0;
}
