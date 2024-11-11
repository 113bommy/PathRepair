#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int x[105];
  for (int i = 0; i < 105; i++) x[i] = 0;
  for (int i = 1; i <= m; i++) {
    int temp, max = -1, index = -1;
    for (int j = 1; j <= n; j++) {
      cin >> temp;
      if (temp > max) {
        max = temp;
        index = j;
      }
    }
    x[index]++;
  }
  int high = -1;
  int in = -1;
  for (int i = 1; i <= n; i++) {
    if (x[i] > high) {
      high = x[i];
      in = i;
    }
  }
  cout << in;
  return 0;
}
