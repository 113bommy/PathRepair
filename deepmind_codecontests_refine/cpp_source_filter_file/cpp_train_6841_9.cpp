#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main() {
  int n, k, cnt = 1;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  b[cnt] = 1;
  for (int i = 2; i <= n; i++) {
    int j;
    for (j = 1; j < cnt; j++) {
      if (a[i] == a[b[j]]) break;
    }
    if (j == cnt) {
      cnt++;
      b[cnt] = i;
    }
  }
  if (cnt < k)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl << b[1];
    for (int i = 2; i <= k; i++) cout << " " << b[i];
    cout << endl;
  }
  return 0;
}
