#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a = 0;
    cin >> a;
    if (a > 0)
      sum += a;
    else
      sum -= a;
  }
  cout << sum;
}
