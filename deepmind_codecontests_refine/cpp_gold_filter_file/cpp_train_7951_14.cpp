#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0;
  cin >> n;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      double tmp = i * i + j * j;
      if (sqrt(tmp) == (int)sqrt(tmp) && sqrt(tmp) <= n) c++;
    }
  cout << c << endl;
  return 0;
}
