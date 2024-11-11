#include <bits/stdc++.h>
using namespace std;
int kk[1000005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int numb[n];
  map<long long, long long> qq;
  for (int i = 0; i < n; i++) cin >> numb[i];
  for (int i = 0; i < n; i++) qq[numb[i]]++;
  for (int i = 0; i <= m; i++) kk[i] = 0;
  if (m == 1) {
    cout << 1 << " " << qq[1] << '\n';
    for (int i = 0; i < n; i++) {
      if (numb[i] == 1) cout << i + 1 << " ";
    }
    return 0;
  }
  for (auto i : qq) {
    if (i.first < m) {
      for (int j = 1;; j++) {
        if (1LL * i.first * j > m) break;
        kk[1LL * i.first * j] += i.second;
      }
    } else
      break;
  }
  int answ1 = 0;
  int answ2 = 0;
  for (int i = 1; i <= m; i++) {
    if (answ2 < kk[i]) {
      answ2 = kk[i];
      answ1 = i;
    }
  }
  if (answ1 == 0) {
    cout << 1 << " " << 0 << '\n';
    cout << '\n';
    return 0;
  }
  cout << answ1 << " " << answ2 << '\n';
  for (int i = 0; i < n; i++) {
    if (answ1 % numb[i] == 0) cout << i + 1 << " ";
  }
  return 0;
}
