#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, a, num = 0;
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a < h) {
      num++;
    } else {
      num += 2;
    }
  }
  cout << num << endl;
  return 0;
}
