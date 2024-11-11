#include <bits/stdc++.h>
using namespace std;
int n, x[101], y[101], f[101], cnt = 0;
void DFS(int i) {
  f[i] = cnt;
  for (int j = 0; j < n; j++)
    if (!f[j] && (x[i] == y[i] || y[i] == y[j])) DFS(j);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; i++)
    if (!f[i]) {
      cnt++;
      DFS(i);
    }
  cout << cnt - 1 << endl;
  return 0;
}
