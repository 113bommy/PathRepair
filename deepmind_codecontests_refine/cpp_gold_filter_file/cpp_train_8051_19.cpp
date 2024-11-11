#include <bits/stdc++.h>
using namespace std;
int main() {
  float n, a, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sum = sum + a;
  }
  cout << sum / n;
  return 0;
}
