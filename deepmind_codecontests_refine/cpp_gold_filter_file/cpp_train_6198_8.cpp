#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> m, r;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    r.push_back(x);
  }
  double y = 0;
  for (int i = 0; i < 1000000; i++) {
    bool yes = false;
    for (int j = 0; j < n; j++) {
      if (i % m[j] == r[j]) {
        yes = true;
        break;
      }
    }
    if (yes == true) {
      ++y;
    }
  }
  printf("%.5lf\n", y / (double)1000000);
}
