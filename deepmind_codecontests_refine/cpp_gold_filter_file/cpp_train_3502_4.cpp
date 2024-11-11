#include <bits/stdc++.h>
using namespace std;
int same(string a, string b) {
  int l1 = a.length();
  int l2 = b.length();
  if (l1 != l2 + 1)
    return 1;
  else {
    for (int i = 0; i < l2; i++) {
      if (a[i] != b[i]) return 1;
    }
    return 0;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  string a[n + m], b[n + m];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = n; i < n + m; i++) {
    cin >> a[i] >> b[i];
    int l = b[i].length();
  }
  for (int i = n; i < n + m; i++) {
    for (int j = 0; j < n; j++) {
      if (same(b[i], b[j]) == 0) {
        cout << a[i] << " " << b[i] << " #" << a[j] << endl;
      }
    }
  }
  return 0;
}
