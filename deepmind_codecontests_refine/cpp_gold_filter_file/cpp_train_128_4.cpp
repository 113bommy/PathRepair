#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int b[m];
    for (int i = 0; i < m; i++) cin >> b[i];
    int freq[1000] = {0};
    for (int i = 0; i < n; i++) {
      if (freq[a[i] - 1] == 0) freq[a[i] - 1] = 1;
    }
    int flag = 0;
    int el = 0;
    for (int i = 0; i < m; i++) {
      if (freq[b[i] - 1] == 1) {
        flag = 1;
        el = b[i];
      }
    }
    if (flag == 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl << 1 << " " << el << endl;
  }
  return 0;
}
