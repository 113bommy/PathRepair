#include <bits/stdc++.h>
const int N = 1e5 + 10;
using namespace std;
void mian() {
  int a, b;
  cin >> a >> b;
  int l = abs(a - b);
  int t = min(a, b);
  if (l % 2) {
    cout << (t + 1) * 2 << endl;
    int cn1 = l / 2, cn2 = l / 2 + 1;
    for (int i = 0; i <= t; i++) {
      printf("%d %d ", cn1, cn2);
      cn1 += 2;
      cn2 += 2;
    }
  } else {
    cout << t + 1 << endl;
    int cn1 = l / 2;
    for (int i = 0; i <= t; i++) {
      printf("%d ", cn1);
      cn1 += 2;
    }
  }
  cout << endl;
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    mian();
  }
}
