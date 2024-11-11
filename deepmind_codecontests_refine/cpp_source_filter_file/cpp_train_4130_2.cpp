#include <bits/stdc++.h>
using namespace std;
int n, a[51], used[51];
vector<int> p;
int main() {
  cin >> n;
  for (int k = 1; k <= n; k++) {
    cin >> a[k];
  }
  for (int k = n; k > 0; k--) {
    if (used[a[k]] == 0) {
      p.push_back(a[k]);
      used[a[k]] = 1;
    }
  }
  cout << p.size() << endl;
  for (int i = p.size() - 1; i >= 0; i--) cout << p[i] << " ";
  return 0;
}
