#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int N = 2e7 + 6;
int vis[N], n;
int x[N], y[N];
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    vis[x[i]] = 1;
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
    vis[y[i]] = 1;
  }
  int ct = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ct += vis[x[i] ^ y[j]];
  if (ct % 2 == 0) {
    cout << "Karen" << endl;
  } else {
    cout << "Koyomi" << endl;
  }
  return 0;
}
