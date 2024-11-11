#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5, mum = 1e9 + 7;
int Pow(int A, long long B) {
  int num = 1;
  while (B) {
    if (B & 1) num = 1LL * num * A % mum;
    A = 1LL * A * A % mum;
    B >>= 1;
  }
  return num;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, k, r, c, ax, ay, bx, by;
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
  cout << (ax == bx && bx == by ? Pow(k, 1LL * n * m)
                                : Pow(k, 1LL * n * m - 1LL * r * c))
       << '\n';
  return 0;
}
