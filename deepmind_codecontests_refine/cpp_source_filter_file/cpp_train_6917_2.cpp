#include <bits/stdc++.h>
using namespace std;
int main() {
  int days, people, status = 0;
  cin >> days;
  cin >> people;
  int *check;
  check = new int[days + 1];
  for (int i = 0; i < days; i++) check[i] = 0;
  for (int i = 0; i < people; i++) {
    int k, z;
    cin >> k;
    cin >> z;
    while (k <= z) {
      check[k - 1]++;
      k++;
    }
  }
  for (int i = 0; i < days - 1; i++)
    if ((check[i] != 1) && (status == 0)) {
      cout << i + 1 << ' ';
      cout << check[i];
      status = 1;
    }
  if (status == 0) cout << "OK";
  return 0;
}
