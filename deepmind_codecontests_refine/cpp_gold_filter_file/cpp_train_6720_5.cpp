#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[101], b[101], n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  int sa = 0, sb = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      sa++;
      sb++;
    } else if (a[i] > b[i])
      sa++;
    else
      sb++;
  }
  if (sa > sb) cout << "Mishka";
  if (sb > sa) cout << "Chris";
  if (sa == sb) cout << "Friendship is magic!^^";
  return 0;
}
