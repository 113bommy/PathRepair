#include <bits/stdc++.h>
#pragma warning(disable : 4786)
using namespace std;
map<string, int> m;
map<int, int> le;
map<int, int> bt;
map<string, int>::iterator it;
int k[2500];
int main() {
  int n, i, b, tot, les, c;
  string a;
  for (i = 0; i <= 2000; i++) k[i] = 2000;
  double perle, perbt;
  scanf("%d", &n);
  getchar();
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    if (m[a] < b) m[a] = b;
  }
  tot = m.size();
  printf("%d\n", tot);
  i = 0;
  for (it = m.begin(); it != m.end(); it++) {
    k[i++] = it->second;
  }
  sort(k, k + tot);
  les = 0;
  for (i = 0; i < tot; i++) {
    n = k[i];
    c = 0;
    while (k[i] == n) {
      c++;
      i++;
    }
    les += c;
    le[n] = les;
    bt[n] = tot - les;
    i--;
  }
  for (it = m.begin(); it != m.end(); it++) {
    b = it->second;
    perle = (le[b] * 100 / (tot * 1.0));
    perbt = (bt[b] * 100 / (tot * 1.0));
    if (perle >= 99)
      cout << it->first << " "
           << "pro\n";
    else if (perle >= 90)
      cout << it->first << " "
           << "hardcore\n";
    else if (perle >= 80)
      cout << it->first << " "
           << "average\n";
    else if (perle >= 50)
      cout << it->first << " "
           << "random\n";
    else
      cout << it->first << " "
           << "noob\n";
  }
  return 0;
}
