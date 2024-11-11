#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ara[32];
  for (int i = 0; i <= 30; i++) {
    ara[i] = pow(2, i) - 1;
  }
  int x = n;
  vector<int> v;
  int f = 0;
  int cnt = 0;
  for (int i = 0;; i++) {
    for (int j = 0; j <= 30; j++) {
      if (x == ara[j]) {
        f = 1;
        break;
      }
    }
    if (f == 1) {
      break;
    }
    if (i % 2 == 0) {
      int g = log(x) / log(2);
      for (int j = g; j >= 0; j--) {
        int e = pow(2, j);
        int m = x ^ e;
        if (m > x) {
          x = m;
          v.push_back(j);
          break;
        }
      }
    } else {
      x++;
    }
    cnt++;
  }
  cout << cnt << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
