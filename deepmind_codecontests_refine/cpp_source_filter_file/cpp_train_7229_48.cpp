#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c;
  cin >> n >> m;
  while (n >= 1 && m >= 1) {
    c++;
    n--;
    m--;
  }
  if (c % 2 == 0) {
    cout << "Malvika" << endl;
  } else {
    cout << "Akshat" << endl;
  }
}
