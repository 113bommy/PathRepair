#include <bits/stdc++.h>
using namespace std;
static const int mx = 10e5 + 10;
int v[mx] = {-1};
int n;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    v[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    int x, k;
    scanf("%d%d", &x, &k);
    k--;
    if ((x - 1) > v[k]) {
      cout << "NO" << endl;
      return 0;
    } else {
      v[k] = max(v[k], x);
    }
  }
  cout << "YES" << endl;
  return 0;
}
