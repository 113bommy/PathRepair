#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct data {
  int t, g;
};
int memo[250][4][66000];
int n, t;
data in[20];
int f(int time, int genre, int bit) {
  if (memo[time][genre][bit] != -1) return memo[time][genre][bit];
  if (time == t) return memo[time][genre][bit] = 1;
  if (time > t) return memo[time][genre][bit] = 0;
  int RE = 0;
  for (int i = 0; i < n; i++)
    if (in[i].g != genre && !(bit & (1 << i))) {
      RE = (RE + f(time + in[i].t, in[i].g, bit | (1 << i))) % mod;
    }
  return memo[time][genre][bit] = RE;
}
int main() {
  cin >> n >> t;
  for (int i = 0; i < n; i++) cin >> in[i].t >> in[i].g;
  memset(memo, -1, sizeof(memo));
  cout << f(0, 0, 0);
}
