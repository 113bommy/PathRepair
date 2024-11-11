#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> p(n + 1), a(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[i] = x;
    p[x] = i;
  }
  long long nr = 0;
  for (int i = 1; i <= m; ++i) {
    int b;
    cin >> b;
    nr += ((p[b] - 1) / k) + 1;
    if (p[b] == 1) {
      continue;
    }
    int x = p[b];
    p[b]--;
    p[a[p[b] - 1]]++;
    swap(a[x], a[x - 1]);
  }
  cout << nr << '\n';
  return 0;
}
