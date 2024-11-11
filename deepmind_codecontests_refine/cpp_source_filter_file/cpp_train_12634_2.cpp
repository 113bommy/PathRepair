#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> v[100010];
int main() {
  cin >> n;
  cout << n - 1 << endl;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    cout << 2 << " " << a << " " << b << endl;
    v[a].push_back(i);
    v[b].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < v[i].size() - 1; j++)
      cout << v[i][j] << " " << v[i][j + 1] << endl;
}
