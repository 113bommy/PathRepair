#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int i = 1;
  while (true) {
    if (i == n + 1) {
      i = 1;
    }
    if (m < i) {
      break;
    }
    m -= i;
    i++;
  }
  cout << m;
}
