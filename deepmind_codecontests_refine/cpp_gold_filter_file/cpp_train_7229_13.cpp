#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, min;
  cin >> n >> m;
  min = (n < m) ? n : m;
  (min & 1) ? cout << "Akshat" << endl : cout << "Malvika" << endl;
  return 0;
}
