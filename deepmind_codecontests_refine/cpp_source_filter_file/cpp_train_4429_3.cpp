#include <bits/stdc++.h>
using namespace std;
int a[101010], b[101010];
int c[101101];
int ans;
int cnt;
int x, mx;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; n >= i; i++) {
    cin >> a[i];
  }
  for (int i = 1; n >= i; i++) {
    cin >> b[i];
    cnt += b[i];
    c[i] = cnt;
  }
  cnt = 0;
  for (int i = 1; n >= i; i++) {
    mx = max(0, a[i] - m * c[i]);
    ans += mx;
    mx = 0;
  }
  for (int i = n; i >= 0; i--) {
    cnt += b[i];
    c[i] = cnt;
  }
  cnt = 0;
  for (int i = n; i >= 0; i--) {
    x = max(0, a[i] - m * c[i]);
    cnt += x;
    x = 0;
  }
  if (ans > cnt) cout << "Limak";
  if (ans < cnt)
    cout << "Radewoosh";
  else
    cout << "Tie";
}
