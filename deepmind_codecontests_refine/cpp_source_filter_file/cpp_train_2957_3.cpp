#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int a[100005];
int main() {
  int n, m, i, j, nr, x, y, found;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (i = 0; i <= n - 1; i++) a[i] = i + 1;
  nr = 10000000 / n;
  std::srand(std::time(NULL));
  for (i = 1; i <= nr; i++) {
    random_shuffle(a, a + n);
    for (j = 0; j <= m - 1; j++) {
      found = 0;
      for (vector<int>::iterator it = v[a[j]].begin(); it != v[a[j]].end();
           it++)
        if (*it == a[(j + 1) % n]) {
          found = 1;
          break;
        }
      if (found == 1) break;
    }
    if (j > m) break;
  }
  if (i <= nr) {
    for (i = 1; i <= m; i++) cout << a[i] << " " << a[(i + 1) % n] << '\n';
  } else
    cout << "-1";
  return 0;
}
