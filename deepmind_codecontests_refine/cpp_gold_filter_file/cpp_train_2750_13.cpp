#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int *y = new int[1001];
  for (int i = 0; i < 1001; i++) y[i] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    y[x]++;
  }
  int c = 0;
  int max = 0;
  for (int i = 0; i < 1001; i++) {
    if (y[i] > 0) {
      c++;
      if (y[i] > max) max = y[i];
    }
  }
  cout << max << " " << c << endl;
  return 0;
}
