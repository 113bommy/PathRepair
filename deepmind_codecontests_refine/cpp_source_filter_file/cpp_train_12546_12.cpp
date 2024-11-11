#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, *n1;
  long long sum = 0;
  cin >> n;
  n1 = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> n1[i];
  }
  sort(n1, n1 + n);
  for (int i = 0; i < n; i++) {
    sum += n1[i];
  }
  int z = 0;
  while (sum % 2 != 0) {
    if (n1[z] % 2 == 0) {
      z++;
    }
    sum -= n1[z];
    z++;
  }
  cout << sum << endl;
  return 0;
}
