#include <bits/stdc++.h>
using namespace std;
int bs[10];
int n, k;
long long undef = -((long long)(1) << 55);
vector<long long> g[100000];
int parseInt(const string& s) {
  int ans = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == '-') {
      ans = -ans;
    } else {
      ans += bs[s.length() - 1 - i] * (s[i] - int('0'));
    }
  }
  return ans;
}
void go(int pt) {
  long long prev = undef;
  for (int i = 0; i < g[pt].size(); i++) {
    if (g[pt][i] != undef) {
      if (g[pt][i] > prev) {
        prev = g[pt][i];
      } else {
        printf("Incorrect sequence");
        exit(0);
      }
    }
  }
  int lf = -1;
  int rg = -1;
  while (lf < (int)g[pt].size() || rg < (int)g[pt].size()) {
    while (lf + 1 < g[pt].size() && g[pt][lf + 1] != undef) {
      lf++;
    }
    if (lf == g[pt].size() - 1) break;
    while (rg + 1 < g[pt].size() && (rg <= lf || g[pt][rg + 1] == undef)) {
      rg++;
    }
    rg++;
    long long lfbound, rgbound;
    if (lf == -1) {
      lfbound = undef;
    } else {
      lfbound = g[pt][lf] + 1;
    }
    if (rg == g[pt].size()) {
      rgbound = -undef;
    } else {
      rgbound = g[pt][rg] - 1;
    }
    if (rgbound - lfbound + 1 < rg - lf - 1) {
      printf("Incorrect sequence");
      exit(0);
    }
    int pflf = -(rg - lf - 1) / 2;
    int pfrg = (rg - lf - 1) / 2 + ((rg - lf - 1) % 2 == 0);
    if (pflf < lfbound) {
      for (int i = lf + 1; i < rg; i++) {
        g[pt][i] = lfbound++;
      }
      continue;
    } else if (pfrg > rgbound) {
      for (int i = rg - 1; i > lf; i--) {
        g[pt][i] = rgbound--;
      }
      continue;
    } else {
      for (int i = lf + 1; i < rg; i++) {
        g[pt][i] = pflf++;
      }
      continue;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  bs[0] = 1;
  for (int i = 1; i < 10; i++) bs[i] = bs[i - 1] * 10;
  cin >> n >> k;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "?") {
      g[i % k].push_back(undef);
    } else {
      g[i % k].push_back(parseInt(s));
    }
  }
  for (int i = 0; i < k; i++) {
    go(i);
  }
  for (int i = 0; i < n; i++) {
    printf("%I64d ", g[i % k][i / k]);
  }
  return 0;
}
