#include <bits/stdc++.h>
using namespace std;
const int oo = 100010;
int n, a[oo], x, p;
vector<int> v[oo], r;
bool c[oo];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v[x].push_back(i);
    if (!c[x]) r.push_back(x);
    c[x] = true;
  }
  sort(r.begin(), r.end());
  for (int i = 0; i < r.size(); i++) {
    if (v[r[i]].size() == 1)
      a[r[i]] = 0;
    else {
      int p = v[r[i]][1] - v[r[i]][0];
      a[r[i]] = p;
      for (int j = 2; j < v[r[i]].size(); j++) {
        if (v[r[i]][j] - v[r[i]][j - 1] != p) {
          a[r[i]] = (-1);
          break;
        }
      }
    }
  }
  for (int i = 0; i < r.size(); i++)
    if (a[r[i]] != (-1)) p++;
  cout << p << endl;
  if (p) {
    for (int i = 0; i < r.size(); i++)
      if (a[r[i]] != (-1)) cout << r[i] << ' ' << a[r[i]] << endl;
  }
  return 0;
}
