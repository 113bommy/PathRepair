#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[105] = {0};
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    a[d]++;
  }
  int sum = 0;
  for (int i = 0; i < 102; i++)
    if (a[i] % 2 == 0)
      sum += a[i];
    else if (a[i] > 2)
      sum += (a[i] - 1);
  cout << sum / 4 << endl;
  return 0;
}
