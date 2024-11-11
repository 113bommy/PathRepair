#include <bits/stdc++.h>
using namespace std;
template <typename T>
T nextInt() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * p;
}
const int maxN = (int)3e5 + 10;
const int INF = (int)1e9 + 5;
const int mod = (int)1e9 + 7;
const long long LLINF = (long long)1e15;
int k, n;
long long b, c;
long long best = LLINF;
long long a[maxN];
int md(int x) { return ((x % 5) + 5) % 5; }
struct val {
  long long add;
  long long sum;
  long long x;
  val() : add(0), sum(0), x(0) {}
  bool operator<(const val &a) const { return sum < a.sum; }
};
struct item {
  int mod;
  long long add;
  long long sum;
  multiset<val> values;
  multiset<int> T;
  void addX(int x) {
    val temp;
    while (md(x) != mod) {
      temp.add += c;
      x++;
    }
    temp.sum = temp.add + (INF + mod - x) / 5 * 1LL * min(b, 5 * c);
    temp.x = x;
    add += temp.add;
    sum += temp.x;
    values.insert(temp);
    T.insert(x);
    while (values.size() > k) {
      auto iter = prev(values.end());
      sum -= iter->x;
      add -= iter->add;
      T.erase(T.find(iter->x));
      values.erase(iter);
    }
  }
  int mx() { return *prev(T.end()); }
  item() {}
  item(int mod) : mod(mod), add(0), sum(0) {}
};
item items[5];
int main() {
  for (int i = 0; i < 5; ++i) {
    items[i] = item(i);
  }
  n = nextInt<int>();
  k = nextInt<int>();
  b = nextInt<long long>();
  c = nextInt<long long>();
  for (int i = 0; i < n; ++i) {
    a[i] = nextInt<int>();
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      items[j].addX(a[i]);
    }
    if (items[0].values.size() < k) continue;
    for (int j = 0; j < 5; ++j) {
      long long B = items[j].mx() * 1LL * k - items[j].sum;
      assert(B % 5 == 0);
      long long cur = items[j].add + min(b, c * 5) * 1LL * (B / 5);
      best = min(best, cur);
    }
  }
  printf("%I64d\n", best);
  return 0;
}
