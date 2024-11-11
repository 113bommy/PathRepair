#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ex[n], e[n];
  int temp = n;
  int i = 0;
  while (temp--) {
    cin >> ex[i] >> e[i];
    i++;
  }
  int sum = e[0], m = e[0];
  for (int j = 1; j < n; j++) {
    sum = sum - ex[j] + e[j];
    if (sum > m) {
      m = sum;
    }
  }
  cout << m << endl;
  return 0;
}
