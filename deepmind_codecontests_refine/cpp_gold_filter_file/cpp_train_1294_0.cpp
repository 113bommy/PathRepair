#include <bits/stdc++.h>
using namespace std;
int main() {
  double n;
  cin >> n;
  double sum = 0, y;
  for (int i = 0; i < n; i++) {
    cin >> y >> y;
    sum += y;
  }
  sum = sum / n;
  cout << sum + 5 << endl;
  return 0;
}
