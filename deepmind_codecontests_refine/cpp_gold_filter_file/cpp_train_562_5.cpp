#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main() {
  scanf("%lld %lld", &a, &b);
  if (a == 0) {
    cout << "-" << b * b << endl;
    for (int i = 0; i < b; i++) cout << "x";
    cout << endl;
  } else if (b == 0) {
    cout << a * a << endl;
    for (int i = 0; i < a; i++) cout << "o";
    cout << endl;
  } else if (b == 1) {
    cout << a * a - 1 << endl;
    cout << "x";
    for (int i = 0; i < a; i++) cout << "o";
    cout << endl;
  } else {
    long long maior = -100000000000, temp = 0, esc = 0;
    for (int i = 1; i <= min(a, b - 1); i++) {
      long long p1 = (((b / (i + 1)) + 1) * ((b / (i + 1)) + 1));
      long long p2 = (b / (i + 1)) * (b / (i + 1));
      long long qtdp1 = (b % (i + 1));
      long long qtdp2 = ((i + 1) - (b % (i + 1)));
      temp = 0;
      temp -= (p1 * qtdp1);
      temp -= (p2 * qtdp2);
      temp += (a - i + 1) * (a - i + 1);
      temp += ((i - 1));
      if (maior < temp) {
        maior = temp;
        esc = i;
      }
    }
    cout << maior << endl;
    long long passou = 0;
    for (int i = 0; i < esc; i++) {
      if (passou < (b % (esc + 1))) {
        passou++;
        for (int j = 0; j < ((b / (esc + 1)) + 1); j++) {
          cout << "x";
        }
      } else {
        for (int j = 0; j < ((b / (esc + 1))); j++) {
          cout << "x";
        }
      }
      if (i == 0) {
        for (int j = 0; j < a - esc + 1; j++) cout << "o";
      } else {
        cout << "o";
      }
    }
    for (int i = 0; i < ((b / (esc + 1))); i++) cout << "x";
    cout << endl;
  }
  return 0;
}
