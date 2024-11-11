#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, t[22], c;
  cin >> n;
  for (int i = 0; i < 20; i++) t[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c >= 0)
      t[c]++;
    else
      t[c + 21]++;
  }
  c = 0;
  for (int i = 1; i < 11; i++) {
    c += t[i] * t[21 - i];
  }
  cout << c + t[0] * (t[0] - 1) / 2;
}
