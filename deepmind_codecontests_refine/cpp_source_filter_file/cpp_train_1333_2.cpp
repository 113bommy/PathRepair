#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0;
  int ma = 0;
  for (int i = 0; i < 5; ++i) {
    int a;
    cin >> a;
    int t = (a + 9) / 10;
    sum += t;
    ma = max(ma, t - a);
  }
  cout << sum - ma << endl;
}
