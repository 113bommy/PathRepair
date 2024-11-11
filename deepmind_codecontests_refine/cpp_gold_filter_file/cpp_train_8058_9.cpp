#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  cin >> n;
  cin >> m;
  map<int, int> m1, m2;
  vector<int> v1(n), v2(m);
  for (i = 0; i < n; i++) {
    cin >> v1[i];
    m1[v1[i]]++;
  }
  for (i = 0; i < m; i++) cin >> v2[i];
  for (i = 0; i < n; i++) {
    m2[i] = m1.size();
    m1[v1[i]]--;
    if (m1[v1[i]] == 0) m1.erase(v1[i]);
  }
  for (i = 0; i < m; i++) {
    cout << m2[v2[i] - 1] << endl;
  }
}
