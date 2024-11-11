#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int frnd[512] = {0}, bit_frnd[512] = {0};
  vector<vector<pair<long long int, long long int> > > piz(512);
  for (long long int i = 0; i < n; i++) {
    long long int a;
    cin >> a;
    long long int num = 0;
    for (long long int ii = 0; ii < a; ii++) {
      long long int x;
      cin >> x;
      x--;
      num += (1 << x);
    }
    frnd[num]++;
  }
  for (long long int i = 0; i < m; i++) {
    long long int p, a, num = 0;
    cin >> p >> a;
    for (long long int ii = 0; ii < a; ii++) {
      long long int x;
      cin >> x;
      x--;
      num += (1 << x);
    }
    piz[num].push_back({p, i + 1});
  }
  for (long long int i = 0; i < 512; i++) {
    sort(piz[i].begin(), piz[i].end());
  }
  for (long long int i = 0; i < 512; i++) {
    for (long long int j = 0; j <= i; j++) {
      if (i & j == j) {
        bit_frnd[i] += frnd[j];
      }
    }
  }
  long long int max_satisfied = -1, ai, aj, cost = -1;
  for (long long int i = 0; i < 512; i++) {
    if (piz[i].size() == 0) continue;
    for (long long int j = i + 1; j < 512; j++) {
      if (piz[j].size() == 0) continue;
      long long int satisfied = bit_frnd[i | j];
      if (satisfied > max_satisfied) {
        max_satisfied = satisfied;
        cost = piz[i][0].first + piz[j][0].first;
        ai = piz[i][0].second;
        aj = piz[j][0].second;
      } else if (satisfied == max_satisfied) {
        if (cost > piz[i][0].first + piz[j][0].first) {
          cost = piz[i][0].first + piz[j][0].first;
          ai = piz[i][0].second;
          aj = piz[j][0].second;
        }
      }
    }
  }
  for (long long int i = 0; i < 512; i++) {
    if (piz[i].size() < 2) continue;
    long long int satisfied = bit_frnd[i];
    if (satisfied > max_satisfied) {
      max_satisfied = satisfied;
      cost = piz[i][0].first + piz[i][1].first;
      ai = piz[i][0].second;
      aj = piz[i][1].second;
    } else if (satisfied == max_satisfied) {
      if (cost > piz[i][0].first + piz[i][1].first) {
        cost = piz[i][0].first + piz[i][1].first;
        ai = piz[i][0].second;
        aj = piz[i][1].second;
      }
    }
  }
  cout << ai << " " << aj << endl;
  return 0;
}
