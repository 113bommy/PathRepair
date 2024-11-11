#include <bits/stdc++.h>
using namespace std;
int main() {
  float x, n, sum = 0;
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> n;
    sum += n;
  }
  cout << sum / x;
  return 0;
}
