#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  long long sumIce = x;
  int leaveChild = 0;
  for (int i = 0; i < n; i++) {
    char a;
    int giveIce;
    cin >> a >> giveIce;
    if (a == '+') {
      sumIce += giveIce;
    } else {
      if (sumIce >= giveIce) {
        sumIce -= giveIce;
      } else {
        leaveChild++;
      }
    }
  }
  cout << sumIce << " " << leaveChild << endl;
  return 0;
}
