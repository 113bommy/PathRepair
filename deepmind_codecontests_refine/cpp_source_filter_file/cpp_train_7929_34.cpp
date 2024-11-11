#include <bits/stdc++.h>
using namespace std;
int vis[210];
int main() {
  int na, nb;
  int a[110], b[110];
  cin >> na;
  for (int i = 1; i <= na; i++) {
    cin >> a[i];
    vis[a[i]]++;
  }
  cin >> nb;
  for (int i = 1; i <= nb; i++) {
    cin >> b[i];
    vis[b[i]]++;
  }
  for (int i = 1; i <= na; i++)
    for (int j = 1; j <= nb; j++)
      if (!vis[a[i] + b[i]]) {
        cout << a[i] << " " << b[i] << endl;
        return 0;
      }
  return 0;
}
