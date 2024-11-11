#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  int cnt = 0, illegal = 0;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    int q;
    cin >> q;
    cnt = 0;
    while (q) {
      if (q % 10 == 4 || q % 10 == 7) cnt++;
      q /= 10;
    }
    if (cnt > b) illegal++;
  }
  cout << a - illegal;
  return 0;
}
