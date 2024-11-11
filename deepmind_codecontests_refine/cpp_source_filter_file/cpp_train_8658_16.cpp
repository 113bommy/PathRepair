#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, l, r, ma = 0, sum = 1, minn = 1, maxx = 1;
  cin >> n >> l >> r;
  int c = r, count = l;
  c--;
  count--;
  while (count--) {
    sum *= 2;
    minn += sum;
  }
  sum = 1;
  while (c--) {
    sum *= 2;
    maxx += sum;
    ma = sum;
  }
  maxx += (n - (r)) * ma;
  minn += (n - l);
  return cout << minn << " " << maxx << "\n", 0;
}
