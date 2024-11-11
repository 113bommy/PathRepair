#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    if (m == 2)
      cout << m << endl;
    else
      cout << m / 2 << endl;
  }
  return 0;
}
