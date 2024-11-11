#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 1, sum = 1;
  cin >> n;
  for (int i = 1; i < n; i++) {
    k = k + i;
    sum = sum + k;
  }
  cout << sum << endl;
  return 0;
}
