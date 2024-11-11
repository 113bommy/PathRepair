#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mid, m, a;
  cin >> n >> m;
  if (n == 1) {
    cout << "1" << endl;
    return 0;
  }
  if (n % 2 == 1)
    mid = (n / 2) + 1;
  else
    mid = n / 2;
  if (m < mid)
    a = m + 1;
  else if (m > mid)
    a = m - 1;
  else if (m == mid && mid % 2 == 0)
    a = m + 1;
  else
    a = m - 1;
  cout << a << endl;
  return 0;
}
