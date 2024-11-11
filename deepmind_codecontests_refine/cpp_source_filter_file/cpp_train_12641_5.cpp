#include <bits/stdc++.h>
using namespace std;
void swap(long long int &a, long long int &b) {
  long long int temp = a;
  a = b;
  b = temp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, x, y, z, p;
  cin >> n >> m >> x >> y >> z >> p;
  x = x % 4;
  y = y % 2;
  z = z % 4;
  for (long long int t1 = 0; t1 < p; t1++) {
    long long int i, j;
    long long int a, b;
    cin >> i >> j;
    long long int row = n, col = m;
    for (long long int t = 0; t < x; t++) {
      a = j;
      b = row - i + 1;
      i = a;
      j = b;
      swap(row, col);
    }
    for (long long int t = 0; t < y; t++) {
      a = i;
      b = col - j + 1;
      i = a;
      j = b;
    }
    for (long long int t = 0; t < z; t++) {
      a = col - j + 1;
      b = i;
      i = a;
      j = b;
      swap(row, col);
    }
    cout << a << " " << b << "\n";
  }
}
