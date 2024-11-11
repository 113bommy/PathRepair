#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i = 1;
  cin >> n >> m;
  while (m > i) {
    m = m - i;
    i++;
    i = i % n;
    if (i == 0) {
      i = n;
    }
  }
  cout << m << endl;
  return 0;
}
