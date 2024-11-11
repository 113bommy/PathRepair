#include <bits/stdc++.h>
using namespace std;
const int N = 3;
int a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    if (a[0] > 0)
      cout << "BitLGM" << endl;
    else
      cout << "BitAryo" << endl;
  } else if (n == 2) {
    if (a[0] > a[1]) swap(a[0], a[1]);
    int temp = (int)sqrt(5.0 * a[1]);
    if (temp != a[1] + 2 * a[0])
      cout << "BitLGM" << endl;
    else
      cout << "BitAryo" << endl;
  } else {
    if (a[0] ^ a[1] ^ a[2])
      cout << "BitLGM" << endl;
    else
      cout << "BitAryo" << endl;
  }
  return 0;
}
