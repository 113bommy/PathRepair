#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<bool> seen(m + 1, false);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    while (a <= b) {
      seen[a] = true;
      a++;
    }
  }
  vector<int> v;
  for (int i = 1; i <= m; ++i) {
    if (seen[i] == false) v.emplace_back(i);
  }
  cout << v.size() << endl;
  for (int x : v) cout << x << ' ';
}
