#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> v;
  for (int i = 0; i < n; i++) {
    vector<int> tmp;
    for (int i = 0; i < 4; i++) {
      int tmp1;
      scanf("%d", &tmp1);
      tmp.push_back(tmp1);
    }
    v.push_back(tmp);
    v[i].push_back(i);
  }
  for (int i = 0; i < v.size(); i++)
    for (int j = 0; j < v.size(); j++)
      if (v[i][0] < v[j][0] && v[i][1] < v[j][1] && v[i][2] < v[j][2]) {
        v.erase(v.begin() + i);
        i--;
        break;
      }
  int mn = v[0][3];
  int ans = v[0][4];
  for (int i = 1; i < v.size(); i++)
    if (mn > v[i][3]) {
      mn = v[i][3];
      ans = v[i][4];
    }
  printf("%d\n", ++ans);
  return 0;
}
