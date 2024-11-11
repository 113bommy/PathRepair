#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 2; i <= n - 1; i++) {
    sum += n * (n + 1);
  }
  cout << sum;
  return 0;
}
