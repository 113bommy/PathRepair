#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int b[1000005];
int obr[1000005];
int cnt[1000005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    f[i]--;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
  }
  for (int i = 0; i < m; i++) {
    obr[f[i]] = i;
    cnt[f[i]]++;
  }
  bool bad = false;
  for (int i = 0; i < m; i++) {
    if (cnt[b[i]] == 0) {
      cout << "Impossible" << endl;
      return 0;
    }
    if (cnt[b[i]] > 1) {
      bad = true;
    }
  }
  if (bad) {
    cout << "Ambiguity" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for (int i = 0; i < m; i++) {
    cout << obr[b[i]] + 1 << " ";
  }
  cout << endl;
}
