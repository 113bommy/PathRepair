#include <bits/stdc++.h>
using namespace std;
const int N = 2050;
int n, k, siz;
bool vis[N];
int main() {
  cin >> n >> k;
  if (n == k) {
    int s = n;
    for (int i = 1; i <= n; i++) {
      cout << "? " << i << endl;
      char res[4];
      cin >> res;
      if (*res == 'Y') s--;
    }
    cout << "! " << s << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) vis[i] = 1;
  if (k == 1) {
    for (int i = 1; i <= n; i++)
      if (vis[i])
        for (int j = i + 1; j <= n; j++)
          if (vis[j]) {
            char res[4];
            cout << "? " << i << endl;
            cin >> res;
            cout << "? " << j << endl;
            cin >> res;
            cout << 'R' << endl;
            if (*res == 'Y') vis[j] = 0;
          }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += vis[i];
    cout << "! " << ans << endl;
    return 0;
  }
  siz = k / 2;
  int m = n / siz;
  for (int L = 1, R = siz; L <= n; L += siz, R += siz) {
    for (int i = L; i <= R; i++) {
      cout << "? " << i << endl;
      char res[4];
      cin >> res;
      if (*res == 'Y') vis[i] = 0;
    }
    cout << 'R' << endl;
  }
  for (int s = 1; s <= m / 2; s++) {
    for (int i = 1, now = s, dlt = 1; i <= m; i++) {
      const int L = (now - 1) * siz + 1, R = now * siz;
      for (int j = L; j <= R; j++)
        if (vis[j]) {
          cout << "? " << j << endl;
          char res[4];
          cin >> res;
          if (*res == 'Y') vis[j] = 0;
        }
      now = s + dlt;
      if (now < 1) now += m;
      if (now > m) now -= m;
      if (dlt > 0)
        dlt = -dlt;
      else
        dlt = -dlt + 1;
    }
    cout << 'R' << endl;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += vis[i];
  cout << "! " << ans << endl;
}
