#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> q;
bool g(int e) {
  for (auto p : q) {
    if (p.first / e != p.second) return false;
  }
  return true;
}
int main() {
  cin >> n >> m;
  n--;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    q.push_back(make_pair(a - 1, b - 1));
  }
  int qq = -1;
  for (int e = 1; e <= n + 1; ++e)
    if (g(e)) {
      if (qq == -1 || qq == n / e)
        qq = n / e;
      else {
        cout << -1 << endl;
        return 0;
      }
    }
  cout << qq + 1 << endl;
  return 0;
}
