#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int *y = new int[1000];
  for (int i = 0; i < 1000; i++) y[i] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    y[x]++;
  }
  int c = 0;
  int max = 0;
  for (int i = 0; i < 1000; i++) {
    if (y[i] > 0) {
      c++;
      if (y[i] > max) max = y[i];
    }
  }
  cout << max << " " << c << endl;
  return 0;
}
