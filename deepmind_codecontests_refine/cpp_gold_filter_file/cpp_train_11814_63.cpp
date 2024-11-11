#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, t = 0, aux = 0;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    if (b % 2 == 0) {
      t += b / 2;
    } else {
      t += (b - 1) / 2;
      aux += 1;
    }
  }
  if (aux != 0) {
    t += (aux % 2 == 0) ? aux / 2 : (aux - 1) / 2;
  }
  cout << t;
}
