#include <bits/stdc++.h>
using pii = std::pair<int, int>;
constexpr int maxa = 1e6 + 100;
long long k[maxa];
const int maxn = 2e5 + 100;
const int S = 450;
long long arr[maxn];
long long ans = 0;
void add(int i) {
  ans += (2 * k[arr[i]] + 1) * arr[i];
  k[arr[i]]++;
}
void remove(int i) {
  ans -= (2 * k[arr[i]] - 1) * arr[i];
  k[arr[i]]--;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, t;
  std::cin >> n >> t;
  for (int i = 0; i < n; i++) std::cin >> arr[i];
  struct query {
    int first, second, i, blnum;
  };
  std::vector<query> v(t);
  for (int i = 0; i < t; i++) {
    std::cin >> v[i].first >> v[i].second;
    --v[i].first, --v[i].second;
    v[i].i = i;
    v[i].blnum = v[i].first / S;
  }
  std::sort(v.begin(), v.end(), [](const query& a, const query& b) {
    if (a.blnum == b.blnum) {
      return a.second < b.second;
    } else {
      return a.blnum < b.blnum;
    }
  });
  long long anss[t];
  int lastl = n, lastr = n - 1;
  for (auto& q : v) {
    while (lastl > q.first) add(--lastl);
    while (lastr < q.second) add(++lastr);
    while (lastl < q.first) remove(lastl++);
    while (lastr > q.second) remove(lastr--);
    anss[q.i] = ans;
  }
  for (int i = 0; i < t; i++) std::cout << anss[i] << "\n";
  return 0;
}
