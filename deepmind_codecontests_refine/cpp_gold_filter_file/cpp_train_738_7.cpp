#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int number, flag = 0, i;
  scanf("%lld", &number);
  if (number % 2 == 0) {
    cout << number / 2;
  } else {
    for (i = 3; i <= sqrt(number); i += 2) {
      if (number % i == 0) {
        cout << ((number - i) / 2) + 1;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "1\n";
    }
  }
  return 0;
}
