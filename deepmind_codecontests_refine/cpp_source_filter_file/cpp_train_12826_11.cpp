#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << '?' << " ";
  for (int i = 1; i <= k; i++) {
    cout << i << " ";
  }
  cout << endl;
  cout.flush();
  int ind = 0;
  long long int val = 0, count1 = 0;
  cin >> ind >> val;
  int ls = -1, gr = -1, lrr = -1, grr = -1;
  for (int i = 1; i <= k; i++) {
    if (i != ind) {
      cout << "?"
           << " ";
      for (int j = 1; j <= k; j++) {
        if (j != i) cout << j << " ";
      }
      cout << n << " " << endl;
      cout.flush();
      int ind2 = 0;
      long long int val2 = 0;
      cin >> ind2 >> val2;
      if (ind2 == ind) {
        count1++;
      } else if (val2 < val) {
        ls = 1;
      } else {
        gr = 1;
      }
    } else {
      cout << '?' << " ";
      for (int j = 1; j <= k; j++) {
        if (j != i) cout << j << " ";
      }
      cout << n << " " << endl;
      int ind2 = 0;
      long long int val2 = 0;
      cout.flush();
      cin >> ind2 >> val2;
      if (val2 < val)
        grr = 1;
      else
        lrr = 1;
    }
  }
  if (ls == 1) {
    cout << '!' << " " << count1 + 1;
  } else if (gr == 1)
    cout << '!' << " " << (k - count1);
  else {
    if (grr = 1)
      cout << '!' << " " << k;
    else
      cout << '!' << " " << 1;
  }
  return 0;
}
