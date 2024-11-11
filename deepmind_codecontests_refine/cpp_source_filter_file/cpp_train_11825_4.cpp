#include <bits/stdc++.h>
using namespace std;
long long int divide(long long int n, long long int l, long long int r,
                     long long int i, long long int j) {
  if (j < l || i > r || n == 0) return 0;
  if (n == 1) return 1;
  long long int mid = i + (j - i) / 2;
  return divide(n >> 1, l, r, i, mid - 1) + divide(n & 1, l, r, mid, mid) +
         divide(n >> 1, l, r, mid + 1, j);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, l, r;
  cin >> n >> l >> r;
  long long int m = n, c = 0;
  while (m >>= 1) ++c;
  c = ((long long int)1 << (c + 1)) - 1;
  cout << divide(n, l, r, 0, c);
  return 0;
}
