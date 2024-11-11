#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int a[1010], ccc;
map<int, int> mp;
int main() {
  int n, k;
  while (cin >> n >> k) {
    mp.clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] -= (i - 1) * k;
    for (int i = 1; i <= n; i++) mp[a[i]]++;
    int ss = 0x3f3f3f3f, tt = 0;
    for (int i = 1; i <= n; i++)
      if (mp[a[i]] > tt && a[i] > 0) tt = mp[a[i]], ss = a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] != ss) cnt++;
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
      if (a[i] != ss) {
        if (a[i] > ss)
          cout << "- ";
        else
          cout << "+ ";
        cout << i << " " << abs(a[i] - ss) << endl;
      }
  }
  return 0;
}
