#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int p, n, a;
  cin >> p >> n;
  bool arr[p], found = false;
  for (int i = 0; i < p; ++i) {
    arr[i] = false;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if ((arr[a % p]) == true && !found) {
      cout << (i + 1);
      found = true;
      break;
    }
    arr[a % p] = true;
  }
  if (!found) {
    cout << "-1";
  }
  return 0;
}
