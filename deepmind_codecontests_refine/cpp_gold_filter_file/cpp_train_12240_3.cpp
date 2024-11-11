#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int desk = (k % (m * 2) == 0 ? m * 2 : k % (m * 2));
  cout << ((k + m * 2 - 1) / (m * 2)) << " " << ((desk + 1) / 2) << " "
       << (k % 2 == 0 ? 'R' : 'L');
}
