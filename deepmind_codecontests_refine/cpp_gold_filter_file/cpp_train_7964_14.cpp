#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b[300000];
  cin >> n;
  int i, k;
  long long sum;
  for (i = 0; i < n; i++) {
    cin >> k;
    b[k] = i + 1;
  }
  sum = 0;
  for (i = 1; i < n; i++) {
    sum += (abs(b[i] - b[i + 1]));
  }
  cout << sum;
  return 0;
}
