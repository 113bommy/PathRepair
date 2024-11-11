#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long total = 0;
  cin >> n;
  long long array[9] = {};
  for (int i = 0; i < 9; i++) array[i] = n / 9 + (n % 9 >= i);
  array[0]--;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      total += array[i] * array[j] * array[(i * j) % 9];
  for (int i = 1; i <= n; i++) total -= n / i;
  cout << total;
  return 0;
}
