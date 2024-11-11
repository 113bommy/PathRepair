#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int R = min(m, n);
  if (R % 2 == 0)
    cout << "Malvika" << endl;
  else
    cout << "Akshat" << endl;
  return 0;
}
