#include <bits/stdc++.h>
using namespace std;
int a[4000], b[4000];
int s[4000], t[4000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) b[i] = a[i];
  sort(b, b + n);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) continue;
    for (int j = i + 1; j < n; ++j) {
      if (b[i] == a[j]) {
        s[cnt] = i;
        t[cnt] = j;
        swap(a[i], a[j]);
        ++cnt;
        break;
      }
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < cnt; ++i) cout << s[i] << " " << t[i] << endl;
  return 0;
}
