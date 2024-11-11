#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + ch - 48;
    ch = getchar();
  }
  return s * f;
}
constexpr int mod = 1e9 + 7;
constexpr int N = 7e6 + 100;
long long a[N];
long long val = 0;
array<int, 60> getnum(long long num) {
  array<int, 60> ans;
  ans.fill(0);
  int cnt = 50;
  while (num) {
    if (num & 1) ans[cnt] = 1;
    num >>= 1;
    cnt--;
  }
  return ans;
}
struct DictionaryTree {
  int tr[N][2];
  int tot = 0;
  void insert(long long num) {
    int root = 0;
    array<int, 60> ans = getnum(num);
    for (int i = 1; i <= 50; ++i) {
      if (!tr[root][ans[i]]) tr[root][ans[i]] = ++tot;
      root = tr[root][ans[i]];
    }
    return;
  }
  long long getans(long long num) {
    int root = 0;
    array<int, 60> ans = getnum(num);
    long long sum = 0;
    for (int i = 1; i <= 50; ++i) {
      if (tr[root][ans[i] ^ 1]) {
        sum = sum + (1LL << (50 - i));
        root = tr[root][ans[i] ^ 1];
      } else
        root = tr[root][ans[i]];
    }
    return max(sum, num);
  }
} tree;
int main() {
  int n = read<int>();
  for (int i = 1; i <= n; ++i) {
    a[i] = read<long long>();
    val ^= a[i];
  }
  long long ans = 0, num = 0;
  for (int i = n; i >= 0; --i) {
    ans = max(ans, tree.getans(val));
    num ^= a[i];
    val ^= a[i];
    tree.insert(num);
  }
  cout << ans << endl;
}
