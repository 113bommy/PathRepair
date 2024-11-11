#include <bits/stdc++.h>
using namespace std;
void update(int i, int j) {}
int main() {
  int n, m;
  cin >> n >> m;
  map<pair<int, int>, int> x;
  for (int i = 0; i < m; i++) {
    int x1, y1;
    cin >> x1 >> y1;
    if (x1 < y1)
      x[make_pair(x1, y1)] = 1;
    else
      x[make_pair(y1, x1)] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!x[make_pair(i, j)]) {
        int k1 = 2;
        cout << "YES" << endl;
        for (int i1 = 1; i1 <= n; i1++)
          if (i1 == i)
            cout << "1 ";
          else if (i1 == j)
            cout << "2 ";
          else {
            k1++;
            cout << k1 << " ";
          }
        cout << endl;
        k1 = 2;
        for (int i1 = 1; i1 <= n; i1++)
          if (i1 == i)
            cout << "1 ";
          else if (i1 == j)
            cout << "1 ";
          else {
            k1++;
            cout << k1 << " ";
          }
        return 0;
      }
  cout << "NO";
  return 0;
}
