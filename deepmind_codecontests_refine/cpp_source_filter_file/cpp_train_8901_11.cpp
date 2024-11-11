#include <bits/stdc++.h>
using namespace std;
const int oo = 1000000009;
const double eps = 1e-9;
const int mod = 1000000007;
int nos[10];
int main() {
  nos[0] = 6;
  nos[1] = 2;
  nos[2] = nos[3] = 5;
  nos[4] = 4;
  nos[5] = 5;
  nos[6] = 6;
  nos[7] = 3;
  nos[8] = 7;
  nos[9] = 8;
  int a, b, ans = 0;
  cin >> a >> b;
  for (int i = a; i <= b; ++i) {
    int temp = i;
    while (temp) {
      ans += nos[temp % 10];
      temp /= 10;
    }
  }
  cout << ans << "\n";
}
