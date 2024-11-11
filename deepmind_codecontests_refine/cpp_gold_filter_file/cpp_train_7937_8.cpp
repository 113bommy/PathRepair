#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int now = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != i && a[i - 1] == i - 1) cnt++;
    }
    cout << min(cnt, 2) << endl;
  }
  return 0;
}
