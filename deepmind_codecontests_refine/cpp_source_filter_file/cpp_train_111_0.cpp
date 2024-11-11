#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int max = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > max) max = a;
    sum += a;
  }
  int min = (2 * sum + 1) / n + 1;
  if (max < min)
    cout << min;
  else
    cout << max;
  return 0;
}
