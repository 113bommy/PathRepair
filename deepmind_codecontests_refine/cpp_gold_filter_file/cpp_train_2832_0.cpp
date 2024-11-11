#include <bits/stdc++.h>
using namespace std;
ifstream fin("AAtest.in.txt");
int q, n, jada['z' + 1], jadb['z' + 1];
string a, b;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> q;
  while (q--) {
    cin >> n >> a >> b;
    memset(jada, 0, sizeof(jada));
    memset(jadb, 0, sizeof(jadb));
    for (int(i) = (0); ((i)) < ((n)); ((i))++) jada[a[i]]++, jadb[b[i]]++;
    int arv = 0;
    bool on = 0;
    for (char c = 'a'; c <= 'z'; c++) {
      if (jada[c] != jadb[c]) {
        cout << "NO" << endl;
        on = 1;
        break;
      }
      arv = max(arv, jada[c]);
    }
    if (on) continue;
    if (arv > 1) {
      cout << "YES" << endl;
      continue;
    }
    int aa = 0, bb = 0;
    for (int(i) = (0); ((i)) < ((n)); ((i))++) {
      char ca = a[i], cb = b[i];
      for (int j = i + 1; j < n; j++) {
        if (a[j] < ca) aa++;
        if (b[j] < cb) bb++;
      }
    }
    if (aa % 2 != bb % 2) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
      continue;
    }
  }
}
