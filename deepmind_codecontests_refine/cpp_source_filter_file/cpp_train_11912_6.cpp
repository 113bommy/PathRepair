#include <bits/stdc++.h>
using namespace std;
string num;
int d[] = {1, 6, 8, 9};
int main() {
  cin >> num;
  int l = num.length(), j, res = 0, k = 1;
  for (int i = 0; i < 4; i++) {
    for (j = i + 1; j < l && num[j] != d[i] + '0'; j++)
      ;
    swap(num[j], num[i]);
  }
  for (int i = 0; i < l - 4; i++) {
    res = (res * 10 + num[i] - '0') % 7;
    k = (k * 10) % 7;
  }
  res = (7 - res) % 7;
  while ((d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3]) * k % 7 != res)
    next_permutation(d, d + 4);
  for (int i = 0; i < 4; i++) cout << d[i];
  cout << num.substr(4) << endl;
  return 0;
}
