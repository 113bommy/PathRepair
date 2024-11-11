#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 9;
int n;
long long a[MAXN];
vector<vector<long long>> power;
void init() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  vector<long long> delta(n, 0), vis(7, 0);
  int cur = 1;
  while (!vis[cur]) {
    vis[cur] = 1;
    for (int i = 0; i < n; i++) {
      if (cur % 7) delta[i]++;
      ++cur %= 7;
    }
  }
  power.emplace_back(delta);
}
void add(vector<long long>& delta, int k) {
  for (int i = 0; i < n; i++) a[i] += delta[i] * k;
}
bool check() {
  for (int i = 0; i < n; i++)
    if (a[i] <= power.back()[i]) return false;
  return true;
}
int solve() {
  while (check()) {
    vector<long long> delta(n, 0);
    for (int i = 0; i < n; i++) delta[i] = power.back()[i] << 1;
    power.emplace_back(delta);
  }
  reverse(power.begin(), power.end());
  for (auto delta : power) {
    add(delta, -1);
    if (*min_element(a, a + n) < 0) add(delta, 1);
  }
  int cur = 1;
  while (*min_element(a, a + n) > 0) {
    for (int i = 0; i < n; i++) {
      if (cur % 7) a[i]--;
      ++cur %= 7;
    }
  }
  for (int i = 0; i < n; i++)
    if (a[i] == 0) return i + 1;
  return -1;
}
int main() {
  init();
  cout << solve() << endl;
  return 0;
}
