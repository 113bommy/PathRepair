#include <bits/stdc++.h>
using namespace std;
int tavan(int a, int b) {
  int m = 1;
  for (int i = 1; i <= b; i++) {
    m *= a;
  }
  return m;
}
int aval(int a) {
  int f = 1;
  for (int i = 2; i < a; i++) {
    if (a % i == 0) {
      f = 0;
      break;
    }
  }
  return f;
}
int main() {
  int n;
  cin >> n;
  vector<int> vc;
  int l = 0;
  for (int i = 2; i <= n; i++) {
    if (aval(i) == 1) {
      for (int j = 1; j <= n; j++) {
        if (tavan(i, j) > n) {
          break;
        } else {
          vc.push_back(tavan(i, j));
          l += 1;
        }
      }
    }
  }
  cout << l << endl;
  for (int i = 0; i < vc.size(); i++) {
    cout << vc[i] << " ";
  }
}
