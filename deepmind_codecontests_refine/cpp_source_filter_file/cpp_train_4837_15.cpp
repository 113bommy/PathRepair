#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005000;
const int MD = 1000000007;
vector<int> divs[MAXN];
int lp[MAXN];
vector<int> pr;
int phi[MAXN];
int pil[MAXN];
int sum[MAXN][3];
int sum_sq[MAXN];
int sum3[MAXN], sum4[MAXN];
int getPhi(int x) {
  int res = x;
  while (x != 1) {
    int div = lp[x];
    res /= div;
    res *= (div - 1);
    while (x % div == 0) {
      x /= div;
    }
  }
  return res;
}
int getPil(int x) {
  int res = 0;
  for (vector<int>::iterator it = divs[x].begin(); it != divs[x].end(); ++it) {
    res = (res + 1ll * *it * phi[x / *it]) % MD;
  }
  res = (res + MD - x) % MD;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  for (int i = 0; i <= 1000000; ++i) {
    lp[i] = 0;
  }
  for (int i = 2; i <= 1000000; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0;
         j < int(pr.size()) && pr[j] <= lp[i] && 1000000 / i >= pr[j]; ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
  divs[1].clear();
  divs[1].push_back(1);
  for (int i = 2; i <= 1000000; ++i) {
    divs[i].clear();
    if (lp[i] == i) {
      divs[i].push_back(1);
      divs[i].push_back(i);
    } else {
      int div = lp[i], cnt = 0;
      int cur_v = i;
      while (cur_v % div == 0) {
        ++cnt;
        cur_v /= div;
      }
      const vector<int> &from = divs[cur_v];
      divs[i].reserve(from.size() * (cnt + 1));
      for (vector<int>::const_iterator it = from.begin(); it != from.end();
           ++it) {
        for (int cp = 1, j = 0; j <= cnt; cp *= div, ++j) {
          divs[i].push_back(cp * *it);
        }
      }
    }
  }
  for (int i = 1; i <= 1000000; ++i) {
    phi[i] = getPhi(i);
    pil[i] = (getPil(i) - i + 1 + MD) % MD;
  }
  sum_sq[0] = sum3[0] = sum4[0];
  for (int i = 1; i <= 1000000; ++i) {
    int tmp = 1ll * i * i % MD;
    sum_sq[i] = (sum_sq[i - 1] + tmp) % MD;
    tmp = 1ll * i * tmp % MD;
    sum3[i] = (sum3[i - 1] + tmp) % MD;
    tmp = 1ll * i * tmp % MD;
    sum4[i] = (sum4[i - 1] + tmp) % MD;
  }
  for (int i = 0; i < 3; ++i) {
    sum[1][i] = 0;
  }
  for (int i = 2; i <= 1000000; ++i) {
    int add = (sum_sq[i - 2] * 2 % MD + MD - (2 * pil[i]) % MD) % MD;
    sum[i][0] = (sum[i - 1][0] + add) % MD;
    sum[i][1] = (sum[i - 1][1] + 1ll * add * i) % MD;
    sum[i][2] = (sum[i - 1][2] + 1ll * add * i % MD * i) % MD;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;
    if (n > m) {
      swap(n, m);
    }
    int res = 0;
    res = (res + 1ll * (n + 1) * (m + 1) % MD * sum[n][0]) % MD;
    res = (res - 1ll * (n + m + 2) * sum[n][1] % MD + MD) % MD;
    res = (res + sum[n][2]) % MD;
    res = (res + 1ll * (n + 1) * (m + 1) % MD * sum_sq[n]) % MD;
    res = (res - 1ll * (n + m + 2) * sum3[n] % MD + MD) % MD;
    res = (res + sum4[n]) % MD;
    cout << res << '\n';
  }
  return 0;
}
