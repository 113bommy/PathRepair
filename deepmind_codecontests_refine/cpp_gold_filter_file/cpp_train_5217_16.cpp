#include <bits/stdc++.h>
using namespace std;
int main() {
  int cards[11] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 15, 4};
  int n;
  scanf("%d", &n);
  n -= 11;
  if (n < 0 || n > 10)
    cout << 0 << endl;
  else
    cout << cards[n] << endl;
  return 0;
}
