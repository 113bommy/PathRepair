#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T& x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}
const int maxn = 5050, PCNT = 669;
int vis[maxn];
vector<int> primes;
void sieve(int LIM) {
  for (int i = 2; i <= LIM; ++i) {
    if (!vis[i]) vis[i] = i, primes.push_back(i);
    for (auto j : primes) {
      if (i * j > LIM) continue;
      vis[i * j] = j;
      if (i % j == 0) break;
    }
  }
}
int gao(int f, int p) {
  int ret = 0;
  while (f) {
    ret += f / p;
    f /= p;
  }
  return ret;
}
struct Bucket {
  int cnt[PCNT], ptr, tot;
  Bucket() : cnt{}, ptr(PCNT - 1), tot(0) {}
  int back() {
    assert(!empty());
    return ptr;
  }
  void pop() {
    assert(!empty());
    cnt[ptr]--;
  }
  bool empty() {
    while (ptr >= 0 && cnt[ptr] == 0) --ptr;
    return ptr < 0;
  }
} bc[5050];
vector<int> id[PCNT];
int sum(int p) {
  int ret = 0;
  for (auto g : id[p]) ret += bc[g].tot;
  return ret;
}
int main() {
  long long ans = 0;
  int n, x;
  read(n);
  for (int i = 0; i < n; ++i) {
    read(x);
    if (x == 0) x = 1;
    bc[x].tot++;
  }
  sieve(5000);
  for (int i = 2; i <= 5000; ++i) {
    for (int j = 0; j < PCNT; ++j) {
      bc[i].cnt[j] = gao(i, primes[j]);
      ans += 1LL * bc[i].cnt[j] * bc[i].tot;
    }
    id[bc[i].back()].push_back(i);
  }
  for (;;) {
    int opt = 0, csum = sum(opt);
    for (int i = 1; i < PCNT; ++i)
      if (sum(i) > csum) opt = i, csum = sum(i);
    if (csum <= n / 2) break;
    ans -= csum - (n - csum);
    auto vec = id[opt];
    for (int i = 0; i < PCNT; ++i) vector<int>().swap(id[i]);
    for (auto g : vec) {
      bc[g].pop();
      if (!bc[g].empty()) id[bc[g].back()].push_back(g);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
