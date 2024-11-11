#include <bits/stdc++.h>
using namespace std;
int main() {
  int p;
  cin >> p;
  int y[p];
  for (int i = 0; i < p; i++) {
    int k;
    cin >> k;
    y[k - 1] = i + 1;
  }
  cout << y[0];
  for (int i = 1; i < p; i++) {
    cout << " " << y[i];
  }
  return 0;
}
