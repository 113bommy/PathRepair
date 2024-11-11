#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[310], c = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  string s;
  if (a[0]) s += 'P', a[0]--;
  do {
    c = 0;
    for (int i = 1; i < n; i++) {
      s += 'R';
      if (a[i]) {
        c++;
        s += 'P';
        a[i]--;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      s += 'L';
      if (a[i]) {
        c++;
        s += 'P';
        a[i]--;
      }
    }
  } while (c);
  cout << s << endl;
}
