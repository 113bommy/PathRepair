#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  bool isGood = false;
  cin >> n;
  vector<char> level(n);
  for (int i = 0; i < n; i++) {
    cin >> level[i];
  }
  for (int i = 1; i <= n / 4 && !isGood; i++) {
    for (int j = 0; j <= n - (4 * i) + (i - 1) && !isGood; j++) {
      int sequence = 0;
      for (int k = j; k < n && !isGood; k += i) {
        if (level[k] == '*')
          sequence++;
        else {
          if (sequence >= 5) isGood = true;
          sequence = 0;
        }
        if (sequence >= 5) isGood = true;
      }
    }
  }
  if (isGood)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
