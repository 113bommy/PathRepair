#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > V(100007);
long long cal(int n) {
  long long cc = 0;
  for (int i = 0; i < n; i++) {
    int index1 = (i + 1) % n;
    if (index1 < 0) index1 += n;
    int index2 = (i - 1) % n;
    if (index2 < 0) index2 += n;
    int cc1 = 0, cc2 = 0, it1 = 0, it2 = 0;
    while (it1 < V[index1].size() && V[index1][it1] < V[i][0]) it1++;
    while (it2 < V[index2].size() && V[index2][it2] < V[i][0]) it2++;
    for (int j = 1; j < V[i].size(); j++) {
      cc1 = cc2 = 0;
      while (it1 < V[index1].size() && V[index1][it1] < V[i][j]) {
        it1++;
        cc1++;
      }
      while (it2 < V[index2].size() && V[index2][it2] < V[i][0]) {
        it2++;
        cc2++;
      }
      if (cc1 != cc2) cc++;
    }
  }
  return cc;
}
int main() {
  int n, tmp, nn;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    for (int j = 0; j < tmp; j++) {
      scanf("%d", &nn);
      V[i].push_back(nn);
    }
    sort(V[i].begin(), V[i].end());
  }
  cout << cal(n);
  return 0;
}
