#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k, fri = 0;
  cin >> n >> m >> k;
  vector<int> v;
  for (int i = 0; i < m + 1; i++) {
    int t;
    cin >> t;
    v.push_back(t);
  }
  int la = v[m];
  vector<int> labit;
  for (int i = 0; i < 32; i++) {
    if ((1 << i) & la)
      labit.push_back(1);
    else
      labit.push_back(0);
  }
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j < 32; j++) {
      int tembit;
      if ((1 << j) & v[i])
        tembit = 1;
      else
        tembit = 0;
      if (tembit != labit[j]) cnt++;
    }
    if (cnt <= k) fri++;
  }
  cout << fri;
}
int main() {
  int t = 1;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
