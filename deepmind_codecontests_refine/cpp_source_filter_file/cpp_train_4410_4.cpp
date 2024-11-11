#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &key) {
  if (a.second >= key.second) return true;
  return false;
}
int main() {
  int n, i, j, t;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<pair<int, int>> P[26];
  for (i = 1; i < n + 1; i++) {
    P[b[i - 1] - 'A'].push_back({i, n - i + 1});
  }
  for (auto &z : P) sort(z.begin(), z.end());
  vector<long long int> lsum[26], rsum[26], lrsum[26];
  for (i = 0; i < 26; i++) {
    lsum[i].assign((int)((P[i]).size()) + 1, 0);
    rsum[i].assign((int)((P[i]).size()) + 1, 0);
    lrsum[i].assign((int)((P[i]).size()) + 1, 0);
    for (j = 1; j < (int)((P[i]).size()) + 1; j++) {
      lsum[i][j] = lsum[i][j - 1] + P[i][j - 1].first;
      rsum[i][j] = rsum[i][j - 1] + P[i][j - 1].second;
      lrsum[i][j] = lrsum[i][j - 1] +
                    P[i][j - 1].first * (long long int)P[i][j - 1].second;
    }
  }
  long long int sum = 0;
  for (i = 1; i < n + 1; i++) {
    int L = i, R = n - i + 1, c = a[i - 1] - 'A';
    int l, r;
    l = lower_bound(P[c].begin(), P[c].end(), make_pair(L, -1)) - P[c].begin();
    r = upper_bound(P[c].begin(), P[c].end(), make_pair(0, R), comp) -
        P[c].begin();
    l++, r++;
    if (r < l) {
      sum +=
          (long long int)R * (lsum[c][r - 1]) +
          (long long int)L * (rsum[c][(int)((P[c]).size())] - rsum[c][l - 1]) +
          (lrsum[c][l - 1] - lrsum[c][r - 1]);
    } else {
      sum +=
          (long long int)R * (lsum[c][l - 1]) +
          (long long int)L * (rsum[c][(int)((P[c]).size())] - rsum[c][r - 1]) +
          (long long int)L * R * (l - r);
    }
  }
  long long int total = (long long int)n * (n + 1) * (2 * n + 1) / 6;
  cout << fixed << setprecision(9) << (long double)sum / total;
  return 0;
}
