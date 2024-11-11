#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
constexpr int INF = 1e9;
constexpr long long LLINF = 1e18;
constexpr bool LOG = false;
template <class T>
void Log(T t) {
  if (LOG) cerr << t << "\n";
}
template <class T, class... S>
void Log(T t, S... s) {
  if (LOG) cerr << t << "\t", Log(s...);
}
using ll = long long;
struct I {
  ll l, r;
  ll index;
  bool operator<(const I& rhs) const { return r < rhs.r; }
  bool operator>(const I& rhs) const {
    if (r != rhs.r) return r > rhs.r;
    return index < rhs.index;
  }
};
struct B {
  ll l;
  ll index;
  bool operator<(const B& r) const { return l < r.l; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll N, M;
  cin >> N >> M;
  vector<I> island(N);
  vector<I> gaps(N - 1);
  vector<B> bridges(M);
  for (decltype(N) i(0); i < (N); i++) cin >> island[i].l >> island[i].r;
  for (decltype(M) i(0); i < (M); i++)
    cin >> bridges[i].l, bridges[i].index = i + 1;
  sort(begin(bridges), end(bridges));
  for (decltype(N - 1) i(0); i < (N - 1); i++) {
    gaps[i].l = island[i + 1].l - island[i].r;
    gaps[i].r = island[i + 1].r - island[i].l;
    gaps[i].index = i;
  }
  sort(begin(gaps), end(gaps), [](const I& g1, const I& g2) {
    if (g1.l != g2.l)
      return g1.l < g2.l;
    else
      return g1.index < g2.index;
  });
  priority_queue<I, vector<I>, greater<I>> pq;
  auto b = bridges.begin();
  auto g = gaps.begin();
  vector<ll> used(N - 1, -1);
  while (b != bridges.end()) {
    Log("bridge: ", b->l, b->index);
    while (g != gaps.end() && g->l <= b->l) {
      pq.push(*g);
      Log("push", g->l, g->r, g->index);
      g++;
    }
    if (!pq.empty() && pq.top().r < b->l) {
      cout << "No\n";
      return 0;
    }
    if (!pq.empty() && pq.top().l <= b->l && b->l <= pq.top().r) {
      auto& t = pq.top();
      Log("pop", t.l, t.r, t.index);
      used[t.index] = b->index;
      pq.pop();
    }
    b++;
  }
  if (g != gaps.end() || !pq.empty()) {
    cout << "No\n";
    return 0;
  }
  bool f = true;
  cout << "Yes\n";
  for (auto&& x : used) {
    if (f)
      f = false;
    else
      cout << " ";
    cout << x;
  }
  cout << "\n";
  return 0;
}
