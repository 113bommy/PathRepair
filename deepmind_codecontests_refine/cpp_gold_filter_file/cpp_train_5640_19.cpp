#include <bits/stdc++.h>
using namespace std;
bool cmp(int i, int j) { return i < j; }
int MAXCIS = 1e5;
vector<vector<int>> v(MAXCIS);
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int flag = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].size() == 2) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
