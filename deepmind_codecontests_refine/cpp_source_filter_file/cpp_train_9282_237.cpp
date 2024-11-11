#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, x;
  cin >> n >> m >> k;
  x = min(m, k);
  if (n <= m)
    cout << "yes";
  else
    cout << "no";
}
