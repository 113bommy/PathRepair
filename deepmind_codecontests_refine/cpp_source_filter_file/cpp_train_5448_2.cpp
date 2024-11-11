#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:20000000")
using namespace std;
int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
long long rll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const int MAXN = 2e6 + 10;
int s1[MAXN];
int s2[MAXN >> 1];
void solve() {
  int n = ri(), m = ri();
  for (int i = (int)(0); i <= (int)(n - 1); i++) s1[i + n] = s1[i] = ri();
  for (int i = (int)((MAXN >> 1) - 3); i >= (int)(1); i--) s2[i] = 2e9;
  for (int i = (int)(0); i <= (int)(m - 1); i++) s2[ri()] = i;
  queue<pair<int, int> > st;
  int res = 0, R = 0;
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    R = max(i, R);
    if (i && !st.empty() && st.front().first == s1[i - 1]) st.pop();
    while (R < 2 * n) {
      if (R - i == n) break;
      int index;
      index = s2[s1[R]];
      if (index == 2e9) break;
      if (st.empty())
        st.push(make_pair(s1[R], index));
      else {
        int temp = (st.front().second + m) / m;
        index = temp * m + index;
        if (index > st.back().second && st.front().second + m > index)
          st.push(make_pair(s1[R], index));
        else {
          index -= temp * m;
          if (index > st.back().second && st.front().second + m > index)
            st.push(make_pair(s1[R], index));
          else
            break;
        }
      }
      R++;
    }
    res = max(res, (int)st.size());
  }
  cout << res << endl;
}
int main() {
  solve();
  return 0;
}
