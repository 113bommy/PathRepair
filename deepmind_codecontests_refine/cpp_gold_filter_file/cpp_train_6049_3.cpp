#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ara[a];
  for (int i = 0; i < a; i++) {
    cin >> ara[i];
  }
  int cost = 0;
  for (int i = 0, j = a - 1; i < j; i++, j--) {
    if (ara[i] != 2) {
      if (ara[j] == 2) {
        if (ara[i] == 0)
          cost += b;
        else
          cost += c;
      } else {
        if (ara[j] == ara[i])
          continue;
        else {
          cout << -1 << endl;
          return 0;
        }
      }
    } else if (ara[i] == 2) {
      if (ara[j] == 2) {
        if (b > c)
          cost += 2 * c;
        else
          cost += 2 * b;
      } else {
        if (ara[j] == 0) {
          cost += b;
        } else
          cost += c;
      }
    }
  }
  if (a % 2 and ara[a / 2] == 2) {
    if (b > c)
      cost += c;
    else
      cost += b;
  }
  cout << cost << endl;
}
