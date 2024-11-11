#include <bits/stdc++.h>
using namespace std;
int b[105], g[105];
int main() {
  int n, m;
  memset(b, 0, sizeof(b));
  memset(g, 0, sizeof(g));
  cin >> n >> m;
  int boy, girl;
  cin >> boy;
  for (int i = 0; i < boy; i++) {
    int x;
    cin >> x;
    b[x] = 1;
  }
  cin >> girl;
  for (int i = 0; i < girl; i++) {
    int x;
    cin >> x;
    g[x] = 1;
  }
  int lim = n * m;
  for (int i = 0; i <= lim; i++) {
    if (b[i % n] == 0 && g[i % m] == 1) {
      b[i % n] = 1;
      boy++;
    } else if (b[i % n] == 1 && g[i % m] == 0) {
      g[i % m] = 1;
      girl++;
    }
  }
  if (girl == m && boy == n)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
