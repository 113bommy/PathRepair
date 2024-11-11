#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x = i & (-i);
    if (n - x < 0) continue;
    n -= x;
    a.push_back(i);
  }
  if (n > 0) {
    cout << -1;
    return 0;
  }
  cout << a.size() << endl;
  for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  return 0;
}
