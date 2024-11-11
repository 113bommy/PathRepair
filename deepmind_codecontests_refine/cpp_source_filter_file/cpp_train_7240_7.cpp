#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = x;
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] + v[i + 1] << "\t";
  }
  cout << "\n";
  return 0;
}
