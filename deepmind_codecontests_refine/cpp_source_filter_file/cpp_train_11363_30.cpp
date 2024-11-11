#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 3; i < n; i++) {
    sum += i * i - 1;
  }
  cout << sum;
  return 0;
}
