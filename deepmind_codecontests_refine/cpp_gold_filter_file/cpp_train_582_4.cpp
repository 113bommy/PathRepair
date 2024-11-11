#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  a = f * x;
}
struct node {
  int buy, money;
  bool operator<(const node &other) const { return money > other.money; }
} t1, t2;
int n;
long long ans;
priority_queue<node> q;
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    t1.buy = 0;
    read(t1.money);
    if (!q.empty()) {
      t2 = q.top();
      q.pop();
      if (t2.money < t1.money) {
        ans += (long long)t1.money - (long long)t2.money;
        t1.buy = 1;
        if (t2.buy == 1) {
          t2.buy = 0;
          q.push(t2);
        }
      } else {
        q.push(t2);
      }
    }
    q.push(t1);
  }
  printf("%lld", ans);
  return 0;
}
