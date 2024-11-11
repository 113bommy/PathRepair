#include <bits/stdc++.h>
using namespace std;
bool kjg[100002];
int isi[100002];
long long dp[100002];
vector<int> adlis[100002], radlis[100002];
int rut, nvert, u, v;
void ruted(int x) {
  kjg[x] = 1;
  for (int i = 0; i < adlis[x].size(); i++) {
    if (!kjg[adlis[x][i]]) {
      radlis[x].push_back(adlis[x][i]);
      ruted(adlis[x][i]);
    }
  }
}
long long rek(int x) {
  if (radlis[x].size() == 0) {
    return 0;
  } else if (dp[x] != -1) {
    return dp[x];
  } else {
    dp[x] = 0;
    if (x != rut) {
      isi[x]--;
    }
    int jum = 0;
    vector<int> cal;
    cal.clear();
    for (int i = 0; i < radlis[x].size(); i++) {
      if (isi[radlis[x][i]] <= 1) continue;
      if (rek(radlis[x][i]) > 0) {
        cal.push_back(rek(radlis[x][i]));
      }
    }
    for (int i = 0; i < radlis[x].size(); i++) {
      jum += isi[radlis[x][i]];
    }
    sort(cal.begin(), cal.end());
    if (cal.size() > 0) {
      for (int i = cal.size() - 1; i >= 0; i--) {
        dp[x] += (long long)cal[i];
        dp[x] += 2LL;
        isi[x]--;
        if (isi[x] == 0) break;
      }
    }
    if (isi[x] > 0) {
      if (isi[x] < jum) {
        dp[x] += 2LL * isi[x];
        isi[x] = 0;
      } else {
        dp[x] += 2LL * jum;
        isi[x] -= jum;
      }
    }
    return dp[x];
  }
}
int main() {
  scanf("%d", &nvert);
  for (int i = 0; i < nvert; i++) {
    scanf("%d", &isi[i]);
  }
  for (int i = 0; i < nvert - 1; i++) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    adlis[u].push_back(v);
    adlis[v].push_back(u);
  }
  scanf("%d", &rut);
  rut--;
  memset(kjg, 0, sizeof kjg);
  ruted(rut);
  memset(dp, -1, sizeof dp);
  printf("%I64d\n", rek(rut));
  return 0;
}
