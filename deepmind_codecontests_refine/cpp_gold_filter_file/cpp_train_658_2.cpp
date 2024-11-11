#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int a[n];
  int i;
  for (i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  int b[m];
  map<int, int> op;
  int j;
  for (i = 0; i < m; i++) {
    cin >> b[i];
    for (j = 0; j < n; j++) {
      int t = b[i] / a[j];
      if (b[i] == t * a[j]) op[t]++;
    }
  }
  map<int, int>::iterator it = op.begin();
  int mx = 0;
  for (it; it != op.end(); it++) mx = it->second;
  cout << mx << endl;
  return 0;
}
