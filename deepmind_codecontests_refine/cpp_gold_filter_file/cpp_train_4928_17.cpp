#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> chores;
  int u;
  for (int i = 0; i < n; i++) {
    cin >> u;
    chores.push_back(u);
  }
  sort(chores.begin(), chores.end());
  if (chores[b] - chores[b - 1]) {
    cout << chores[b] - chores[b - 1] << endl;
  } else {
    cout << 0;
  }
  return 0;
}
