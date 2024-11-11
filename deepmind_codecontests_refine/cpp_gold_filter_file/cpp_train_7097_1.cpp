#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  long long int coin = 0, input, zero = 0, neg = 0, pos = 0;
  scanf("%d", &num);
  while (num--) {
    scanf("%lld", &input);
    if (input > 0) {
      coin += (input - 1);
      pos++;
    } else if (input < 0) {
      coin += (-1 - input);
      neg++;
    } else
      zero++;
  }
  if ((neg % 2 != 0) && zero == 0) coin += 2;
  if (zero) coin += zero;
  cout << coin << endl;
  return 0;
}
