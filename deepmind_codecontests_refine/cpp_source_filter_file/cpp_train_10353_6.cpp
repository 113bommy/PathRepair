#include <bits/stdc++.h>
using namespace std;
int a[51];
int main(void) {
  int n, v, kn, kv, count = 0;
  cin >> n >> v;
  for (int i = 1; i <= n; i++) {
    cin >> kn;
    for (int j = 1; j <= kn; j++) {
      cin >> kv;
      if (kv < v && a[i] == 0) {
        a[i] = i;
        count++;
      }
    }
  }
  cout << count << endl;
  for (int i = 1; i <= count; i++) {
    if (a[i] != 0) cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
