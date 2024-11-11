#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  int a, b, the;
  cin >> n >> m;
  vector<int> A(n);
  unordered_map<int, int> odd;
  for (int i = 0; i < m; i++) cin >> a >> b, odd[--a] = odd[--b] = 1;
  for (int i = 0; i < n; i++)
    if (!odd[i]) the = i;
  cout << n - 1 << endl;
  for (int i = 0; i < n; i++)
    if (i != the) cout << the + 1 << " " << i + 1 << endl;
  return 0;
}
