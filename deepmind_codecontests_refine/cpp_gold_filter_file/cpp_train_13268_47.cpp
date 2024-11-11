#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, q, cont = 0;
  cin >> n;
  while (n--) {
    cin >> p >> q;
    if (p < q - 1) {
      cont++;
    }
  }
  cout << cont;
  return 0;
}
