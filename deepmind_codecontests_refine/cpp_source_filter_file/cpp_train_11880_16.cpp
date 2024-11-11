#include <bits/stdc++.h>
using namespace std;
vector<int> a[200010];
int main() {
  int x, i, n;
  cin >> n;
  vector<int> b;
  for (i = 2; i <= n; i++) {
    cin >> x;
    a[x].push_back(i);
    a[i].push_back(x);
  }
  for (i = n; i; i = a[i][0]) {
    if (i == 1) {
      b.push_back(1);
      break;
    }
    b.push_back(i);
  }
  reverse(b.begin(), b.end());
  for (i = 0; i < b.size(); i++) cout << b[i];
  return 0;
}
