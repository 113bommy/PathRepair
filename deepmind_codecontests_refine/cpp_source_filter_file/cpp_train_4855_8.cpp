#include <bits/stdc++.h>
using namespace std;
int n, mps[20];
int main() {
  cin >> n;
  for (int i = 1; i <= 30; i++) {
    mps[i] = (pow(2, i) - 1) * pow(2, i - 1);
  }
  for (int i = 30; i >= 1; i--) {
    if (n % mps[i] == 0) {
      cout << mps[i] << endl;
      return 0;
    }
  }
}
