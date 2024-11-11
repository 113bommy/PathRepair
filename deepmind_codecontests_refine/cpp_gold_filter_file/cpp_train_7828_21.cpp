#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c[101] = {0}, d;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> b;
    c[b]++;
    if (c[b] % 2 == 0) {
      d++;
    }
  }
  cout << d / 2 << endl;
}
