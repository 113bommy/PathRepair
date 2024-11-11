#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int N = 5e6 + 10;
map<long long, long long> a;
set<long long> st;
long long c[N];
int main() {
  long long xx;
  scanf("%I64d", &xx);
  int cnt = 0;
  for (int i = 1; i <= 5e6; i++) {
    if (c[i - 1] == -1) c[i] = -1;
    c[i] = c[i - 1] + (long long)i * i;
    if (c[i] < 0) {
      c[i] = -1;
    }
  }
  long long x;
  for (int i = 1; i <= 5e6; i++) {
    x = xx;
    if (c[i - 1] == -1) continue;
    x -= c[i - 1];
    long long tmp = (long long)i * (i - 1) / 2;
    x += tmp * i;
    long long tp = (long long)i * i - tmp;
    if (x > 0 && x % tp == 0) {
      if (i < x / tp) {
        st.insert((long long)i);
        st.insert(x / tp);
        cnt += 2;
        a[(long long)i] = (long long)x / tp;
        a[(long long)x / tp] = (long long)i;
      } else if ((long long)i == x / tp) {
        st.insert((long long)i);
        cnt++;
        a[(long long)i] = (long long)x / tp;
      }
    }
  }
  cout << cnt << endl;
  for (set<long long>::iterator i = st.begin(); i != st.end(); ++i)
    printf("%I64d %I64d\n", (*i), a[(*i)]);
  return 0;
}
