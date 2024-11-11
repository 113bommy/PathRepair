#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int neg = 0;
  bool pos = false;
  int ind[4];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (neg < 3 && a[i] < 0) {
      ind[neg] = i;
      neg++;
    }
    if (!pos && a[i] > 0) {
      ind[3] = i;
      pos = true;
    }
  }
  cout << "1 " << a[ind[0]] << endl;
  if (pos) {
    cout << "1 " << a[ind[3]] << endl;
  } else {
    cout << "2 " << a[ind[1]] << " " << a[ind[2]] << endl;
  }
  pos ? cout << n - 1 : cout << n - 2;
  for (int i = 0; i < n; i++) {
    if (i != ind[0] && i != ind[3] && (pos || (i != ind[1] && i != ind[2])))
      cout << " " << a[i];
  }
  return 0;
}
