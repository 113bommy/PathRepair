#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k;
  cin >> k;
  if (k > 36)
    cout << "-1";
  else {
    if (k % 2 == 1) cout << "9";
    k /= 2;
    for (int i = 0; i < k; i++) cout << "8";
  }
  cout << endl;
  return 0;
}
