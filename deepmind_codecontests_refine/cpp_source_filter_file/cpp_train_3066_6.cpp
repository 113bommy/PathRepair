#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, m, n, h;
char t;
map<string, int> mapa;
string s[122], e, f;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    cin >> e >> f;
    s[i] = e + f;
    mapa[s[i]]++;
  }
  cout << mapa.size();
}
