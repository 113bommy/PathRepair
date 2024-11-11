#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i = 0;
  cin >> b >> a;
  while (1) {
    if (i % 2 == 0) {
      if (a < i)
        return cout << "Valera", 0;
      else
        a -= i;
    } else {
      if (b < i)
        return cout << "Vladik", 0;
      else
        b -= i;
    }
    i++;
  }
}
