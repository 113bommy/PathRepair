#include <bits/stdc++.h>
using namespace std;
vector<int> edg[100001];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edg[a].push_back(b);
    edg[b].push_back(a);
  }
  int r = 0;
  vector<int> l;
  for (int i = 1; i <= n; i++) {
    if (edg[i].size() >= 3)
      if (!r)
        r = i;
      else {
        cout << "No";
        return 0;
      }
    else if (edg[i].size() == 1)
      l.push_back(i);
  }
  cout << "Yes" << endl;
  if (!r) {
    cout << 1 << endl << l[0] << ' ' << l[1];
    return 0;
  }
  cout << l.size() << endl;
  for (int a : l) {
    cout << r << ' ' << a << endl;
  }
  return 0;
}
