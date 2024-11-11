#include <bits/stdc++.h>
using namespace std;
int main() {
  string name[] = {"S", "M", "L", "XL", "XXL"};
  int count[5];
  int i;
  for (i = 0; i < 5; i++) cin >> count[i];
  int k, j, p;
  cin >> k;
  string size;
  for (j = 0; j < k; j++) {
    cin >> size;
    for (i = 0; i < 5; i++)
      if (size == name[i]) break;
    for (p = 0; p <= i; p++) {
      if (i + p < 5 && count[i + p] > 0) {
        count[i + p]--;
        cout << name[i + p] << "\n";
        break;
      } else if (i - p > -1 && count[i - p] > 0) {
        count[i - p]--;
        cout << name[i - p] << "\n";
        break;
      }
    }
  }
}
