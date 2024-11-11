#include <bits/stdc++.h>
using namespace std;
long long dx(int h, long long n, int l) {
  long long mid;
  if (h == 0) return 0;
  mid = (long long)(1 << (h - 1));
  if (n >= mid)
    if (l == 1)
      return (long long)(1 << h) - 1 + dx(h - 1, n - mid, l) + 1;
    else
      return dx(h - 1, n - mid, !l) + 1;
  else if (l == 1)
    return dx(h - 1, n, !l) + 1;
  else
    return (long long)(1 << h) - 1 + dx(h - 1, n, l) + 1;
}
int main() {
  int h;
  long long n;
  cin >> h >> n;
  cout << dx(h, n - 1, 1) << endl;
  return 0;
}
