#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << (n % 2 ? n * n : n * n + 1) / 2 << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << ((i + j) % 2 == 0 ? 'C' : '.');
    cout << endl;
  }
  return 0;
}
