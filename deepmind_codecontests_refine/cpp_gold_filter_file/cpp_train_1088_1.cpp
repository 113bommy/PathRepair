#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  int k;
  cin >> n >> k;
  int num1 = 2, k1 = k;
  k--;
  int num2 = n;
  int count = 1;
  cout << 1 << " ";
  while (k--) {
    if (count & 1)
      cout << num2 << " ", num2--;
    else
      cout << num1 << " ", num1++;
    count++;
  }
  for (int i = k1 + 1; i <= n; i++) {
    if (k1 & 1)
      cout << num1 << " ", num1++;
    else
      cout << num2 << " ", num2--;
  }
  puts("");
  return 0;
}
