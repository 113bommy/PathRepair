#include <bits/stdc++.h>
using namespace std;
vector<int> s;
bool compara(int i1, int i2) { return s[i1] < s[i2]; }
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  s = vector<int>(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vector<int> indice(n);
  for (int i = 0; i < n; i++) indice[i] = i;
  sort(indice.begin(), indice.end(), compara);
  vector<int> v(n);
  for (int i = 0; i < n; i++) v[i] = s[indice[i]];
  vector<int> a(n), b(n);
  int inf = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (2 * inf <= v[i]) {
      a[i] = inf;
      b[i] = v[i] - inf;
      inf++;
    } else if (v[i] >= inf) {
      a[i] = v[i];
      b[i] = 0;
    } else {
      a[i] = 0;
      b[i] = v[i];
    }
  }
  vector<int> sola(n), solb(n);
  for (int i = 0; i < n; i++) {
    sola[indice[i]] = a[i];
    solb[indice[i]] = b[i];
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << sola[i];
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << solb[i];
  }
  cout << endl;
}
