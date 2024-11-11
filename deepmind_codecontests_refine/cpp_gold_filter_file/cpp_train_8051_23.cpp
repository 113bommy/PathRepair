#include <bits/stdc++.h>
using namespace std;
int main() {
  cout.precision(14);
  long double n, k;
  long double sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    sum += k;
  }
  cout << sum / n << endl;
}
