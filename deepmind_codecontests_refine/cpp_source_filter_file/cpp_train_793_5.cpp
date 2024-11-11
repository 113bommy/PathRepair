#include <bits/stdc++.h>
const long long mod = (long long)1e9 + 7;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string str;
  cin >> str;
  vector<vector<long long>> vc(26);
  long long n = (long long)str.length();
  for (long long i = 0; i < n; i++) {
    vc[str[i] - 'a'].push_back(i);
  }
  vector<long long> mx(26, 0);
  for (long long i = 0; i < 26; i++) {
    if (vc[i].size() <= 1) continue;
    for (long long j = 0; j < (long long)vc[i].size() - 1; j++) {
      mx[i] = max(mx[i], vc[i][j + 1] - vc[i][j]);
    }
    mx[i] = max(mx[i], n - vc[i][(long long)vc[i].size() - 1] + vc[i][0]);
  }
  long long fv = 0, tot = n;
  for (long long i = 0; i < 26; i++) {
    if (vc[i].size() == 0) continue;
    if (vc[i].size() == 1) {
      fv++;
      continue;
    }
    long long pp = 0;
    for (long long j = 1; j <= mx[i]; j++) {
      vector<long long> chh(26, 0);
      for (long long k = 0; k < (long long)vc[i].size(); k++) {
        chh[str[(vc[i][k] + j) % n] - 'a']++;
      }
      long long px = 0;
      for (long long k = 0; k < 26; k++) {
        if (chh[k] == 1) px++;
      }
      pp = max(pp, px);
    }
    fv += pp;
  }
  double ans = (double)fv / (double)tot;
  cout << fixed << setprecision(8) << ans << "\n";
  return 0;
}
