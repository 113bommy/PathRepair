#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    int a[110], b[110];
    int s[2001] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
  }
  return 0;
}
