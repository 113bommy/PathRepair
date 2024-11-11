#include <bits/stdc++.h>
using namespace std;
int i, j, k, n;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    j = j + k;
  }
  cout << (double)j / n;
}
