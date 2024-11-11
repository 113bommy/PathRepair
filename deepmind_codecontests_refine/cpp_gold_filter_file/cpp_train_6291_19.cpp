#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  int n;
  scanf("%d", &n);
  int ans = INT_MAX;
  int sum = 0;
  vector<int> K;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    K.push_back(k);
  }
  vector<vector<int> > P;
  for (int i = 0; i < (int)K.size(); i++) {
    vector<int> v;
    for (int j = 0; j < K[i]; j++) {
      int p;
      scanf("%d", &p);
      v.push_back(p);
    }
    P.push_back(v);
  }
  for (int i = 0; i < (int)K.size(); i++) {
    for (int j = 0; j < (int)P[i].size(); j++) {
      sum += P[i][j] * 5;
    }
    sum += K[i] * 15;
    ans = min(ans, sum);
    sum = 0;
  }
  printf("%d\n", ans);
  return 0;
}
