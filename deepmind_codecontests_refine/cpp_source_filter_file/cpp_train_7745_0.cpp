#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[2000010];
  scanf("%s", ch);
  return ch;
}
const int MAX_LG = 21;
const long long maxn = 1e5 + 10;
const long long maxm = 1e4;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 100;
long long a[maxn];
set<long long> st;
long long start, target;
long long cur;
inline long long calc(long long now) {
  if (now == target) return 0;
  long long mini = now - 1;
  for (long long i = 0; i < cur; i++) {
    if (now - (now % a[i]) >= target)
      mini = min(mini, now - (now % a[i]));
    else
      swap(a[cur - 1], a[i]), cur--;
  }
  return calc(mini) + 1;
}
int32_t main() {
  long long n = in();
  for (long long i = 0; i < n; i++) {
    a[i] = in();
    st.insert(a[i]);
  }
  for (auto pt : st) a[cur++] = pt;
  start = in(), target = in();
  cout << calc(start) << "\n";
}
