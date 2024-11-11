#include <bits/stdc++.h>
using namespace std;
int n, m;
int *f, *b;
map<int, int> ff, bb, fff;
int main() {
  cin >> n >> m;
  f = new int[n];
  b = new int[m];
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    ff[f[i]]++;
    fff[f[i]] = i + 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    bb[b[i]]++;
    if (ff[b[i]] == 0) {
      cout << "Impossible";
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if ((ff[f[i]] > 1) && bb[f[i]] > 0) {
      cout << "Ambiguity";
      return 0;
    }
  }
  cout << "Possible" << endl;
  for (int i = 0; i < m; i++) {
    cout << fff[b[i]] << " ";
  }
}
