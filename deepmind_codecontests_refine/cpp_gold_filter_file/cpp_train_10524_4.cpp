#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  int sum = a1 + a2 + a3 + a4;
  int rank = 1;
  int x1, x2, x3, x4;
  for (int i = 2; i <= n; i++) {
    cin >> x1 >> x2 >> x3 >> x4;
    if (x1 + x2 + x3 + x4 > sum) rank++;
  }
  cout << rank << endl;
  return 0;
}
