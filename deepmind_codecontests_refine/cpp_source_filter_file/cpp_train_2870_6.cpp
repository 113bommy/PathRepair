#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long least = 1e+9;
  while (m--) {
    long long l, r;
    cin >> l >> r;
    least = min(least, (r - l + 1));
  }
  cout << least << "\n";
  long long counter = 0;
  for (int i = 1; i <= n; i++) {
    cout << counter % least;
    counter++;
  }
  cout << "\n";
}
