#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int p[k];
  int max = -1;
  for (int i = 0; i < k; ++i) {
    cin >> p[i];
    if (p[i] > max) {
      max = p[i];
    }
  }
  if (max - 25 <= 0) {
    cout << 0 << endl;
  } else {
    cout << max - 25 << endl;
  }
}
