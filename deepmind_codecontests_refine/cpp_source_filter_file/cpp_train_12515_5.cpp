#include <bits/stdc++.h>
using namespace std;
int verifica(int nr, vector<int> v[]) {
  if (nr % 2 != 0) return 1;
  int m = nr % 10000;
  bool ok = true;
  for (int i = 0; i < v[m].size(); i++)
    if (v[m][i] == nr) {
      ok = false;
      break;
    }
  if (ok == true) {
    v[m].push_back(nr);
    return 0;
  }
  return 1;
}
int main() {
  ifstream f("f.in");
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k, mutari = 0;
    cin >> k;
    vector<int> v[9999];
    for (int j = 0; j < k; j++) {
      int nr;
      cin >> nr;
      if (nr % 2 == 0)
        if (verifica(nr, v) == 0) {
          mutari++;
          while (nr % 2 == 0) {
            nr << 1;
            if (nr % 2 == 0 && verifica(nr, v) == 0)
              mutari++;
            else
              break;
          }
        }
    }
    cout << mutari << "\n";
  }
  return 0;
}
