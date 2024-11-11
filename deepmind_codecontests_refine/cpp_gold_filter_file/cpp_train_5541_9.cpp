#include <bits/stdc++.h>
using namespace std;
int n, mm, i, a[1000000], b[1000000], ma, mi, k, c[10000], j;
string aa[101];
map<string, int> m;
map<string, int> l;
int main() {
  cin >> n >> mm;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a, a + n);
  sort(b, b + n, greater<int>());
  for (i = 0; i < mm; i++) {
    cin >> aa[i];
    m[aa[i]]++;
  }
  for (i = 0; i < mm; i++) {
    if (m[aa[i]]) c[j++] = m[aa[i]], m[aa[i]] = 0;
  }
  sort(c, c + m.size(), greater<int>());
  for (i = 0; i < m.size(); i++) mi += (c[i] * b[i]), ma += (c[i] * a[i]);
  cout << ma << " " << mi;
}
