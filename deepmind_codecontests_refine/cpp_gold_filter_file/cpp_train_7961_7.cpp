#include <bits/stdc++.h>
using namespace std;
int pr[1020304], pn, tmp[1020304];
long long f[3005][7005];
bool flag[1020304];
long long List[1020304];
vector<long long> vec[1020304];
int main() {
  for (int i = 2; i <= 1000000; ++i) flag[i] = 1;
  for (int i = 2; i <= 1000000; ++i)
    if (flag[i]) {
      pr[++pn] = i;
      for (int j = i + i; j <= 1000000; j += i) flag[j] = false;
    }
  long long x;
  cin >> x;
  map<long long, int> Map;
  int Tot = 0;
  for (long long i = 1; i * i <= x; ++i)
    if (x % i == 0) {
      long long a = i, b = x / i;
      List[Map[a] = ++Tot] = a;
      if (a != b) List[Map[b] = ++Tot] = b;
    }
  f[0][1] = 1;
  for (int i = 2; i <= 1000000; ++i)
    if (flag[i]) {
      long long tmp = i;
      while (tmp < x) {
        if (x % (tmp + 1) == 0) vec[i].push_back(tmp + 1);
        tmp = tmp * i;
      }
    }
  int num = 0;
  for (int i = 1; i <= 1000000; ++i)
    if (vec[i].size()) tmp[++num] = i;
  for (int i = 0; i <= num - 1; ++i)
    for (int j = 1; j <= Tot; ++j)
      if (f[i][j]) {
        long long rem = x / List[j];
        f[i + 1][j] += f[i][j];
        for (auto &y : vec[tmp[i + 1]])
          if (rem % y == 0) {
            f[i + 1][Map[List[j] * y]] += f[i][j];
          }
      }
  long long ans = 0;
  for (int i = 1; i <= Tot; ++i)
    if (f[num][i]) {
      long long rem = x / List[i] - 1;
      bool fl = rem > tmp[num] && rem > 1;
      for (int j = 1; j <= pn; ++j) {
        if ((long long)pr[j] * pr[j] > rem) break;
        if (rem % pr[j] == 0) {
          fl = false;
          break;
        }
      }
      if (fl || (List[i] == x)) ans += f[num][i];
    }
  cout << ans << endl;
  return 0;
}
