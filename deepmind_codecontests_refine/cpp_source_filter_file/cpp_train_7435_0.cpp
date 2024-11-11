#include <bits/stdc++.h>
using namespace std;
int a[100500], b[100500];
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    if (b[i] / 2 + b[i] % 2 > a[i] || a[i] == 1)
      sum--;
    else
      sum += (b[i] / 2 + b[i] % 2) * (b[i] / 2);
  }
  cout << sum << endl;
  return 0;
}
