#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  long long ar[3];
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> ar[0] >> ar[1] >> ar[2];
    cout << setprecision(17);
    cout << floor((ar[0] + ar[1] + ar[2]) / 2) << endl;
  }
}
