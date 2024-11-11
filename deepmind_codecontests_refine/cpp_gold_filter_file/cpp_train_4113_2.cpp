#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int a[1000005], b[1000005];
int ans[805];
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= 2 * n; i++) {
    for (int j = 1; j < i; j++) {
      int x;
      cin >> x;
      v.push_back(x);
      a[x] = i;
      b[x] = j;
    }
  }
  sort(v.begin(), v.end());
  int x = v.size();
  for (int i = x - 1; i >= 0; i--) {
    if (ans[a[v[i]]] == 0 and ans[b[v[i]]] == 0) {
      ans[a[v[i]]] = b[v[i]];
      ans[b[v[i]]] = a[v[i]];
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    cout << ans[i] << " ";
  }
}
