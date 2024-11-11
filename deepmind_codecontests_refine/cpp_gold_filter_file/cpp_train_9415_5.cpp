#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, o, m, sum = 0;
  cin >> t >> m;
  for (int i = 0; i < t; i++) {
    cin >> o;
    sum += o;
  }
  int sum2 = (t - 1) * 10;
  sum2 += sum;
  if (sum2 > m) {
    cout << "-1" << endl;
  } else {
    int s = m - sum;
    int n = s / 5;
    cout << n << endl;
  }
  return 0;
}
