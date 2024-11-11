#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt = 0;
  int n, m, z;
  cin >> n >> m >> z;
  vector<int> t(z + 1);
  for (int i = 0; i < z + 1; i += n) t[i] = 1;
  for (int i = m; i < z + 1; i += m) cnt += t[i];
  cout << cnt;
}
