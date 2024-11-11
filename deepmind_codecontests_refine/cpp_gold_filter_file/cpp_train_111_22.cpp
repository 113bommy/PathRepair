#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int *mas = new int[n];
  int sum = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
    sum += mas[i];
    if (mas[i] > max) max = mas[i];
  }
  int k = max;
  while ((k * n - sum) <= sum) {
    k++;
  }
  cout << k;
  return 0;
}
