#include <bits/stdc++.h>
using namespace std;
double const pi = 3.1415926536;
int main() {
  map<int, int> boy;
  map<int, int> girl;
  int n, m;
  cin >> n >> m;
  int b;
  cin >> b;
  int x[b];
  for (int i = 0; i < b; i++) {
    cin >> x[i];
    boy[x[i]] = 1;
  }
  int g;
  cin >> g;
  int y[g];
  for (int i = 0; i < g; i++) {
    cin >> y[i];
    girl[y[i]] = 1;
  }
  for (int d = 0; d < 10000; d++) {
    if (girl[d % m] == 1 || boy[d % n] == 1) {
      girl[d % m] = 1;
      boy[d % n] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (boy[i] == 0) {
      cout << "No";
      return (0);
      ;
    }
  }
  for (int i = 0; i < m; i++) {
    if (girl[i] == 0) {
      cout << "No";
      return (0);
      ;
    }
  }
  cout << "Yes";
}
