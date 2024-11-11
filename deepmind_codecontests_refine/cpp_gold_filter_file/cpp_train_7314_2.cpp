#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
struct mint {
  int val = 0;
  mint() {}
  mint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }
  mint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
  }
  mint operator+=(mint oth) {
    val += oth.val;
    val -= (val >= M) ? M : 0;
    return *this;
  }
  mint operator-=(mint oth) {
    val -= oth.val;
    val += (val < 0) ? M : 0;
    return *this;
  }
  mint operator*=(mint oth) {
    val = 1LL * val * oth.val % M;
    return *this;
  }
  void operator++() {
    ++val;
    if (val == M) {
      val = 0;
    }
  }
  void operator--() {
    --val;
    if (val == -1) {
      val = M - 1;
    }
  }
  mint operator-() {
    mint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }
  friend mint operator+(mint a, mint b) { return mint(a) += b; }
  friend mint operator-(mint a, mint b) { return mint(a) -= b; }
  friend mint operator*(mint a, mint b) { return mint(a) *= b; }
  friend bool operator==(mint a, mint b) { return a.val == b.val; }
  friend bool operator!=(mint a, mint b) { return a.val != b.val; }
  friend ostream &operator<<(ostream &out, mint a) {
    out << a.val;
    return out;
  }
  friend mint pow(mint b, long long e = M - 2) {
    mint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= b;
      }
      b *= b;
      e /= 2;
    }
    return res;
  }
};
const int N = 2000;
map<int, int> mono;
mint sum;
int l;
void update(int a, int x) {
  auto it = --mono.upper_bound(a);
  if (it->second <= x) {
    return;
  }
  mono[a] = it->second;
  it = mono.find(a);
  while (it->second >= x) {
    auto nxt = it;
    sum -= (mint)((++nxt)->first - it->first) * (it->second - x);
    mono.erase(it);
    it = nxt;
  }
  mono[a] = x;
}
array<int, 3> candy[N];
multiset<int> where[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k >> l;
  for (int i = 0; i < n; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    candy[i] = {x, y, c - 1};
  }
  sort(candy, candy + n);
  mint ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && candy[i][0] == candy[i - 1][0]) {
      continue;
    }
    sum = (mint)l * l;
    mono.clear();
    mono[l] = -1;
    mono[0] = l;
    fill(where, where + k, multiset<int>());
    for (int j = i; j < n; ++j) {
      where[candy[j][2]].insert(candy[j][1]);
    }
    for (int j = 0; j < k; ++j) {
      where[j].insert(l);
      where[j].insert(-1);
      auto it = where[j].begin();
      while (*it < l) {
        auto nxt = it;
        update(*it + 1, l - *(++nxt));
        it = nxt;
      }
    }
    for (int j = n - 1; j >= i; --j) {
      auto [x, y, c] = candy[j];
      if (j == n - 1 || x != candy[j + 1][0]) {
        int above = candy[i][0] - (i == 0 ? -1 : candy[i - 1][0]);
        int below = (j == n - 1 ? l : candy[j + 1][0]) - x;
        ans += sum * above * below;
      }
      multiset<int> &w = where[c];
      w.erase(w.find(y));
      int prv = *(--w.upper_bound(y));
      int nxt = *w.lower_bound(y);
      update(prv + 1, l - nxt);
    }
  }
  cout << ans << "\n";
}
