#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  string b;
  cin >> b;
  int n = a.size();
  char c, d;
  int idx1 = 0, idx2 = n;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      c = a[i];
      idx1 = i;
      break;
    }
  }
  for (int i = n; i >= 0; i--) {
    if (a[i] != b[i - 1]) {
      d = a[i];
      idx2 = i;
      break;
    }
  }
  if (c != d) {
    cout << 0 << endl;
    return 0;
  }
  cout << idx2 - idx1 + 1 << endl;
  for (int i = idx2; i <= idx1; i++) {
    cout << i + 1 << " ";
  }
  cout << endl;
  return 0;
}
