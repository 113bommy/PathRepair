#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int> > myArr[10000];
int findLog2(int n) {
  int i = 1;
  int count = 0;
  while (i < n) {
    i = i * 2;
    count++;
  }
  return count;
}
void findIntersect(int r1, int r2, int a, set<int>& finalAns) {
  for (int i = 0; i < myArr[a].size(); ++i) {
    pair<pair<int, int>, int> p = myArr[a][i];
    if (!(r2 < p.first.first || r1 > p.first.second)) finalAns.insert(p.second);
  }
}
int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      myArr[a].push_back(make_pair(make_pair(b, c), d));
    } else if (type == 2) {
      int a, b;
      cin >> a >> b;
      int r1 = b;
      int r2 = b;
      set<int> finalAns;
      while (a <= n) {
        findIntersect(r1, r2, a, finalAns);
        if (r1 == 1)
          r1 = 1;
        else if (r1 == 2)
          r1 = 3;
        else {
          int p = findLog2(r1);
          r1 = (p)*2 + (r1 - 1 - p) + 1;
        }
        if (r2 == 1)
          r2 = 2;
        else if (r2 == 2)
          r2 = 4;
        else {
          int p = findLog2(r2);
          if (r2 & (r2 - 1))
            r2 = (p)*2 + (r2 - 1 - p) + 1;
          else
            r2 = (p)*2 + (r2 - 1 - p) + 2;
        }
        a++;
      }
      cout << finalAns.size() << endl;
    }
  }
  return 0;
}
