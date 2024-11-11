#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e6 + 10;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
ll N, M, K, T;
set<Pii> ss;
void AddSeg(int u, int v) {
  int a = (v - u + N) % N, b = (u - v + N) % N;
  if (a < b)
    ss.emplace(u, v);
  else
    ss.emplace(v, u);
}
bool Check(int k) {
  for (auto &p : ss) {
    int a = (p.first + k) % N, b = (p.second + k) % N;
    auto it0 = ss.find(make_pair(a, b));
    auto it1 = ss.find(make_pair(b, a));
    if (it0 == ss.end() && it1 == ss.end()) return false;
  }
  return true;
}
bool Solution() {
  for (int d = 2; d <= sqrt(N); ++d) {
    if (N % d == 0) {
      if (Check(d) || Check(N / d)) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> N >> M) {
    int u, v;
    for (int i = (int)(0); i < (int)(M); ++i) {
      cin >> u >> v;
      AddSeg(u - 1, v - 1);
    }
    if (Solution())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
