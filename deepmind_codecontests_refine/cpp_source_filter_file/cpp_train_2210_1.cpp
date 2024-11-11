#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, t[20], c;
  cin >> n;
  for (int i = 0; i < 20; i++) t[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c >= 0)
      t[c]++;
    else
      t[c + 20]++;
  }
  c = 0;
  for (int i = 1; i < 10; i++) {
    c += t[i] * t[20 - i];
  }
  cout << c + t[0] * (t[0] - 1) / 2;
}
