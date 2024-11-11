#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mn = 1000000001, mni = -1, mnc = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x < mn) {
      mn = x;
      mni = i;
      mnc = 1;
    } else if (x == mn) {
      mnc++;
    }
  }
  if (mnc > 1)
    cout << "Still Rozdil\n";
  else
    cout << mni << endl;
}
