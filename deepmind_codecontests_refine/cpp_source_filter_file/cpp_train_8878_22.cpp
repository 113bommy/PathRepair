#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, temp = 0, count = 0, an[10] = {0}, bn[10] = {0}, i, j, kb = 0,
            ka = 0;
  cin >> a >> b;
  if (b >= a)
    cout << b << endl;
  else {
    temp = a, count = b;
    while (b != 0) {
      bn[kb++] = b % 10;
      b /= 10;
    }
    b = count, count = 0;
    for (i = a; i <= 177777; i++) {
      count = 0;
      ka = 0, j = 0;
      temp = i;
      while (temp != 0) {
        j = temp % 10;
        if (j == 4 || j == 7) an[ka++] = j;
        temp /= 10;
      }
      if (ka == kb) {
        for (j = 0; j < kb; j++)
          if (an[j] == bn[j]) count++;
      }
      if (count == kb) break;
    }
    cout << i << endl;
  }
  return 0;
}
