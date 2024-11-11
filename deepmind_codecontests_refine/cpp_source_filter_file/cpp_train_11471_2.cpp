#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    n = n * 4;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int st = 0, en = n - 1;
    sort(a.begin(), a.end());
    bool flag = 0;
    int res = a[0] * a[n - 1];
    while (st < en) {
      if (a[st] * a[en] != res && a[st + 1] == a[st] && a[en - 1] == a[en]) {
        flag = 1;
        break;
      }
      st = st + 2;
      en = en - 2;
    }
    if (flag == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
