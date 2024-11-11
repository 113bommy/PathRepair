#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
const int maxn = 100005;
long long h;
int n, m, k;
long long pos[maxn];
int treasure[maxn];
int flag[maxn];
long long D[10005];
long long allk[32];
int top;
void fix(priority_queue<pair<long long, int> >& pq) {
  set<pair<long long, int> > st;
  for (int i = 0; i < k; ++i)
    if (D[i] != -1) st.insert({D[i], i});
  while (!st.empty()) {
    auto where = st.begin();
    auto curr = *where;
    st.erase(where);
    if (D[curr.second] != curr.first) continue;
    for (int i = 0; i < top; ++i) {
      const long long val = curr.second + allk[i];
      if (val > h) continue;
      int next = val % k;
      if (D[next] == -1) {
        D[next] = val;
        st.insert({D[next], next});
      } else if (D[next] > val) {
        D[next] = val;
        st.insert({D[next], next});
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    const int bucket = pos[i] % k;
    if (D[bucket] != -1) {
      if (pos[i] >= D[bucket] && flag[i] == 0) {
        pq.push({treasure[i], -i});
        flag[i] = 1;
      }
    }
  }
}
int main() {
  scanf("%I64d", &h);
  n = Rint(), m = Rint(), k = Rint();
  for (int i = 1; i <= n; ++i) scanf("%I64d %d", pos + i, treasure + i);
  memset(D, -1, sizeof D);
  D[1 % k] = 1;
  priority_queue<pair<long long, int> > pq;
  for (int i = 1; i <= n; ++i) {
    const int bucket = pos[i] % k;
    if (D[bucket] != -1) {
      if (pos[i] >= D[bucket]) {
        pq.push({treasure[i], -i});
        flag[i] = 1;
      }
    }
  }
  for (int id = 0; id < m; ++id) {
    const int cmd = Rint();
    if (cmd == 3) {
      while (!pq.empty()) {
        auto curr = pq.top();
        if (treasure[-curr.second] != curr.first) {
          pq.pop();
        } else {
          break;
        }
      }
      long long ans = 0;
      if (!pq.empty()) {
        ans = pq.top().first;
        treasure[-pq.top().second] = -1;
        pq.pop();
      }
      printf("%I64d\n", ans);
    } else if (cmd == 2) {
      const int x = Rint();
      const int c = Rint();
      treasure[x] -= c;
      if (c != 0 && flag[x]) {
        pq.push({treasure[x], -x});
      }
    } else {
      long long x;
      scanf("%I64d", &x);
      int ok = 1;
      for (int i = 0; i < top; ++i)
        if (x % allk[i] == 0) ok = 0;
      if (x % k == 0) ok = 0;
      if (ok) {
        allk[top++] = x;
        fix(pq);
      }
    }
  }
  return 0;
}
