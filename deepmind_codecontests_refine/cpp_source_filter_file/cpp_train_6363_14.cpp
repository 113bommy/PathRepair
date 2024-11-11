#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int x[maxn], y[maxn], vis[maxn];
int main() {
  for (int i = 1; i <= 3; i++) cin >> x[i] >> y[i], vis[x[i]] = y[i];
  sort(x + 1, x + 4);
  sort(y + 1, y + 4);
  cout << x[3] - x[1] + y[3] - y[1] + 1 << endl;
  for (int i = x[1]; i < x[2]; i++) cout << i << " " << vis[x[1]] << endl;
  for (int i = x[2]; i <= x[3]; i++) cout << i << " " << vis[x[3]] << endl;
  for (int i = y[1]; i <= y[3]; i++) cout << x[2] << " " << i << endl;
}
