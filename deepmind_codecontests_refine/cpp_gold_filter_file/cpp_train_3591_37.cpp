#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int R = n - m;
  int L = m - 1;
  if (n == 1) {
    cout << 1 << endl;
    exit(0);
  }
  if (R > L && m != n)
    cout << m + 1 << endl;
  else
    cout << m - 1 << endl;
  return 0;
}
