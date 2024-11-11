#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0, k = 0, a = 0;
  string ch, aux, aux2;
  string test[102];
  cin >> n;
  if (n = 1) {
    cin >> ch;
    cout << ch;
  } else {
    while (i < n) {
      cin >> ch;
      test[i] = ch;
      i += 1;
    }
    for (int j = 1; j < n; j++) {
      aux = test[0];
      if (test[j] == aux) {
        k += 1;
      } else if (test[j] != aux) {
        a += 1;
        aux2 = test[j];
      }
    }
    if (a > k) {
      cout << aux2;
    } else {
      cout << aux;
    }
  }
}
