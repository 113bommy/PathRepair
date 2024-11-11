#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp, t = 0;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> temp;
    t += temp;
  }
  cout << ((n * (n + 1)) / 2) - t << endl;
  return 0;
}
