#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, sum = 0, counter = 0;
  char a, b, c;
  cin >> i;
  while (counter < i) {
    cin >> a >> b >> c;
    if (a == 'x') {
      if (b == '+')
        sum++;
      else
        sum--;
    }
    if (c == 'x') {
      if (a == '+')
        sum++;
      else
        sum--;
    }
    counter++;
  }
  cout << sum;
  return 0;
}
