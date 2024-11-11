#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, i;
  cin >> l >> n;
  int sorted_ara[l + 1], ara[l];
  for (i = 0; i < l; i++) {
    cin >> ara[i];
  }
  sort(ara, ara + l);
  sorted_ara[0] = ara[0] * 2;
  sorted_ara[l] = (n - ara[l - 1]) * 2;
  for (i = 1; i <= l - 1; i++) sorted_ara[i] = ara[i] - ara[i - 1];
  sort(sorted_ara, sorted_ara + l + 1);
  cout << sorted_ara[l] / 2.0 << endl;
  return 0;
}
