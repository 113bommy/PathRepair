#include <bits/stdc++.h>
using namespace std;
int ni() {
  int a;
  scanf("%d", &a);
  return a;
}
long long nll() {
  long long a;
  scanf("%lld", &a);
  return a;
}
const int maxn = 400005;
const long long mod = 1000000007;
int l[2][maxn];
int r[2][maxn];
vector<int> open[2][maxn], close[2][maxn], uniq[2][maxn];
long long lol[2][maxn];
bool valid[2][maxn];
long long fastPow(int w, int p) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    long long x = fastPow(w, p / 2);
    return x * x % mod;
  }
  return fastPow(w, p - 1) * w % mod;
}
int main() {
  int k = ni();
  int n = ni();
  int m = ni();
  vector<int> events;
  for (int j = 0; j < (2); ++j)
    for (int i = 0; i < (j == 0 ? n : m); ++i) {
      l[j][i] = ni();
      r[j][i] = ni();
      events.push_back(l[j][i]);
      events.push_back(r[j][i]);
    }
  reverse(r[0], r[0] + n);
  reverse(l[0], l[0] + n);
  reverse(r[1], r[1] + m);
  reverse(l[1], l[1] + m);
  sort((events).begin(), (events).end());
  events.erase(unique((events).begin(), (events).end()), events.end());
  map<int, int> inv;
  for (int i = 0; i < (events.size()); ++i) inv[events[i]] = i;
  for (int j = 0; j < (2); ++j)
    for (int i = 0; i < ((j == 0 ? n : m)); ++i) {
      valid[j][i] = true;
      l[j][i] = inv[l[j][i]];
      r[j][i] = inv[r[j][i]];
      if (l[j][i] != r[j][i]) {
        open[j][l[j][i]].push_back(i);
        close[j][r[j][i]].push_back(i);
      } else if (uniq[j][l[j][i]].size() == 0) {
        uniq[j][l[j][i]].push_back(i);
      }
    }
  vector<int> stk[2];
  for (int i = 0; i < (events.size()); ++i)
    for (int j = 0; j < (2); ++j) {
      int smallest = k + 1;
      for (int z = 0; z < (open[j][i].size()); ++z) {
        int cur = open[j][i][z];
        if (r[j][cur] >= smallest) {
          valid[j][cur] = false;
          continue;
        }
        smallest = r[j][cur];
        while (stk[j].size() && r[j][stk[j].back()] >= r[j][cur]) {
          valid[j][stk[j].back()] = false;
          stk[j].pop_back();
        }
        stk[j].push_back(cur);
      }
      if (uniq[j][i].size()) {
        while (stk[j].size() && r[j][stk[j].back()] >= r[j][uniq[j][i][0]]) {
          valid[j][stk[j].back()] = false;
          stk[j].pop_back();
        }
        stk[j].push_back(uniq[j][i][0]);
      }
    }
  long long total = 1;
  int lst = 0;
  if (events.size() == 0 || events.back() != k) events.push_back(k);
  int allOpen[2] = {0};
  for (int i = 0; i < (events.size()); ++i) {
    long long pwr2 = fastPow(2, events[i] - lst - 1);
    lst = events[i];
    total = total * pwr2 % mod;
    int closeNow[2] = {0};
    for (int j = 0; j < (2); ++j)
      for (int z = 0; z < (close[j][i].size()); ++z)
        if (valid[j][close[j][i][z]]) {
          assert(closeNow[j] == 0);
          closeNow[j] += lol[j][close[j][i][z]];
          closeNow[j] %= mod;
        }
    int totalNow[2] = {0};
    for (int j = 0; j < (2); ++j)
      totalNow[j] = (total - closeNow[1 - j] + mod) % mod;
    for (int j = 0; j < (2); ++j)
      if (uniq[j][i].size()) totalNow[1 - j] = 0;
    total = (totalNow[0] + totalNow[1]) % mod;
    bool moo[2] = {false};
    for (int j = 0; j < (2); ++j)
      for (int z = 0; z < (open[j][i].size()); ++z)
        if (valid[j][open[j][i][z]]) {
          assert(!moo[j]);
          moo[j] = true;
          lol[j][open[j][i][z]] =
              ((totalNow[1 - j] - (allOpen[j] - closeNow[j] + mod) % mod +
                mod) %
                   mod +
               mod) %
              mod;
          (allOpen[j] += lol[j][open[j][i][z]]) %= mod;
        }
    for (int j = 0; j < (2); ++j) ((allOpen[j] -= closeNow[j]) += mod) %= mod;
  }
  printf("%d\n", (int)(total % mod));
}
