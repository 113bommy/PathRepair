#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
using namespace std;
long long n;
set<long long> st;
long long mxl, mxr;
long long k, b;
inline void Reverse(long long a) {
  k = -k;
  b = a - b;
  if (mxl) mxl = a - mxl, mxr = a - mxr, swap(mxl, mxr);
}
inline long long fake_to_real(long long x) { return k * x + b; }
inline long long real_to_fake(long long x) { return (x - b) * k; }
inline void work() {
  read(n);
  mxl = mxr = 0;
  long long ans = n + n;
  k = 1, b = 0;
  st.clear();
  for (long long i = 1; i <= n; ++i) {
    long long a;
    read(a);
    if (k == 1)
      while (st.size() && fake_to_real(*(--st.end())) >= a)
        st.erase(--st.end());
    else
      while (st.size() && fake_to_real(*st.begin()) >= a) st.erase(st.begin());
    if (mxl && mxr >= a) {
      if (mxl >= a)
        mxl = mxr = 0;
      else
        mxr = a - 1;
    }
    if (!st.size() && !mxl) {
      if (a & 1)
        mxl = 1, mxr = a - 1;
      else
        --ans, st.insert(real_to_fake(a >> 1));
    } else {
      if (a & 1) {
        --ans;
      } else {
        if (st.find(real_to_fake(a >> 1)) != st.end() ||
            (mxl <= (a >> 1) && (a >> 1) <= mxr)) {
          st.clear();
          mxl = mxr = 0;
          st.insert(real_to_fake(a >> 1));
          --ans;
          --ans;
        } else {
          --ans;
          st.insert(real_to_fake(a >> 1));
        }
      }
    }
    Reverse(a);
  }
  printf("%lld\n", ans);
}
signed main() {
  long long _;
  read(_);
  while (_--) work();
  return 0;
}
