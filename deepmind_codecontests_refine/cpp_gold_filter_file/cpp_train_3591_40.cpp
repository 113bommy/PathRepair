#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1000000000")
static int m1[200][200], m2[200];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1)
    cout << 1 << endl;
  else if (m - 1 >= n - m)
    cout << m - 1 << '\n';
  else
    cout << m + 1 << endl;
  return 0;
}
