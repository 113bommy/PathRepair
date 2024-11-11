#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int b[3];
  for (int i = 0; i < 3; i++) b[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i] - 1]++;
  }
  for (int i = 1; i <= 3; i++)
    for (int j = 0; j < 2; j++)
      if (a[j] < a[j + 1]) swap(a[j], a[j + 1]);
  cout << b[0] + b[1];
  return 0;
}
