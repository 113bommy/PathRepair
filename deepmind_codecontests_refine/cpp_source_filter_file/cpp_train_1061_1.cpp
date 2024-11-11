#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int n_f = n / 36;
  int n_i = (n % 36) / 3;
  if ((n % 36) % 3 >= 2) n_i++;
  if (n_i == 12) {
    n_i = 0;
    n_f = 1;
  }
  cout << n_f << ' ' << n_i;
  return 0;
}
