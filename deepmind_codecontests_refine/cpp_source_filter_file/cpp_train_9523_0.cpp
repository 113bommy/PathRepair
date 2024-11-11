#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  int ast = 1;
  for (int i = 1; i < n; i++) ast *= 2;
  int a[102];
  long long l = 0, r = n - 1;
  long long l1 = 1;
  long long r1 = ast;
  int k = 1;
  while (r >= l) {
    long long tm = (l1 + r1) / 2;
    if (tm >= m) {
      a[l] = k;
      l++;
      r1 = tm;
    } else {
      a[r] = k;
      r--;
      l1 = tm;
    }
    k++;
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
