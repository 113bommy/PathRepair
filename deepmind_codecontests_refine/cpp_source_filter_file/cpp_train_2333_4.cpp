#include <bits/stdc++.h>
using namespace std;
const int M = 100000 + 5;
long long int a[M];
vector<int> s[M];
vector<int> big;
int isbig[M];
int common[350][M];
long long int bigsum[M];
long long int bigtag[M];
int mp[M];
int main() {
  time_t t_start, t_end;
  t_start = clock();
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int sz = sqrt(1.0 * n) + 1;
  for (int i = 1; i <= m; i++) {
    int sk;
    cin >> sk;
    for (int j = 0; j < sk; j++) {
      int v;
      cin >> v;
      s[i].push_back(v);
    }
    if (sk >= sz) {
      big.push_back(i);
      isbig[sk] = 1;
      mp[i] = big.size() - 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (isbig[i] == 1) {
      int tmp[M];
      for (int j = 1; j <= n; j++) {
        tmp[j] = 0;
      }
      for (int j = 0; j < s[i].size(); j++) {
        int v = s[i][j];
        tmp[v] = 1;
        bigsum[i] += a[v];
      }
      for (int j = 1; j <= m; j++) {
        if (j != i) {
          int cnt = 0;
          for (int k = 0; k < s[j].size(); k++) {
            int v = s[j][k];
            if (tmp[v] == 1) {
              cnt++;
            }
          }
          common[mp[i]][j] = cnt;
        }
      }
      for (int j = 1; j <= n; j++) {
        tmp[j] = 0;
      }
    }
  }
  for (int query = 0; query < q; query++) {
    char x;
    cin >> x;
    if (x == '+') {
      int k, x;
      cin >> k >> x;
      if (isbig[k] == 0) {
        for (int i = 0; i < s[k].size(); i++) {
          int idx = s[k][i];
          a[idx] += x;
        }
        for (int i = 0; i < big.size(); i++) {
          int kk = big[i];
          long long int num = common[i][k];
          bigsum[kk] = bigsum[kk] + num * x;
        }
      } else {
        bigtag[k] += x;
      }
    } else {
      int k;
      cin >> k;
      if (isbig[k] == 0) {
        long long int s1 = 0;
        for (int i = 0; i < s[k].size(); i++) {
          int idx = s[k][i];
          s1 = s1 + a[idx];
        }
        for (int i = 0; i < big.size(); i++) {
          int kk = big[i];
          s1 = s1 + common[i][k] * bigtag[kk];
        }
        cout << s1 << endl;
      } else {
        long long int s1 = bigsum[k] + bigtag[k] * s[k].size();
        for (int i = 0; i < big.size(); i++) {
          int kk = big[i];
          if (kk != k) {
            s1 = s1 + bigtag[kk] * common[mp[k]][kk];
          }
        }
        cout << s1 << endl;
      }
    }
  }
  t_end = clock();
  return 0;
}
