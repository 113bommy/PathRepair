#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int main() {
  int n, exp = 0;
  cin >> n;
  int v[n], m = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    m = max(m, v[i]);
  }
  int cont = 0, a;
  bool ok, deu;
  while (m >= (1 << cont)) {
    deu = true;
    for (int j = 0; j < cont; j++) {
      ok = false;
      for (int i = 0; i < n; i++) {
        if ((v[i] >> cont) % 2 == 1 && (v[i] >> j) % 2 == 0) {
          ok = true;
        }
      }
      if (!ok) deu = false;
    }
    if (deu) exp = cont;
    cont++;
  }
  for (int i = 0; i < n; i++)
    if ((v[i] >> exp) == 1) ans.push_back(v[i]);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
}
