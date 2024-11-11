#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[2] - a[1] >= 3)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}
