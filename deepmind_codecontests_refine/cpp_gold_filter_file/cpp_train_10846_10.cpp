#include <bits/stdc++.h>
using namespace std;
const int N = 205001;
const double PI = acos(-1);
int n;
long long b[N];
vector<long long> smv[60];
bool cmp(vector<long long>& v1, vector<long long>& v2) {
  return v1.size() > v2.size();
}
signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &b[i]);
    for (int ii = 0; ii < 60; ii++) {
      if (b[i] & (1ll << ii)) {
        smv[ii].push_back(b[i]);
        break;
      }
    }
  }
  sort(smv, smv + 60, cmp);
  cout << n - smv[0].size() << endl;
  for (int i = 1; i < 60; i++) {
    for (int j = 0; j < smv[i].size(); j++) {
      printf("%lld ", smv[i][j]);
    }
  }
}
