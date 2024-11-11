#include <bits/stdc++.h>
using namespace std;
ifstream fin("a.in");
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1)
    cout << 1 << "\n";
  else if (m - 1 > n - m)
    cout << m - 1 << "\n";
  else
    cout << m + 1 << "\n";
}
