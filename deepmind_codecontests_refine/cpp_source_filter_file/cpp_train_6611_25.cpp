#include <bits/stdc++.h>
using namespace std;
int f[100010];
int fp[100010];
int b[100010];
int main() {
  int n, m;
  cin >> n >> m;
  memset(fp, -1, sizeof(fp));
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    if (fp[f[i]] != -1) {
      fp[f[i]] = -2;
      continue;
    }
    fp[f[i]] = i;
  }
  bool imp = false;
  bool amb = false;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    if (fp[b[i]] == -1) imp = true;
    if (fp[b[i]] == -2) imp = true;
  }
  if (imp) {
    cout << "Impossible" << endl;
    return 0;
  }
  if (amb) {
    cout << "Ambiguity" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for (int i = 0; i < m; i++) {
    if (i != 0) cout << " ";
    cout << fp[b[i]] + 1;
  }
  cout << endl;
}
