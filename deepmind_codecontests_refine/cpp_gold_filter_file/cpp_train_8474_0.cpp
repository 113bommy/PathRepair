#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
const int INF = ~(1 << 31);
const double EPS = 1;
const double PI = 3.141592653589793;
long long cnt(vector<long long> &s, int i, int j) {
  vector<long long>::iterator low, up;
  low = lower_bound(s.begin() + j, s.end(), i + (j > 0 ? s[j - 1] : 0));
  if (low != s.end() && (*low) == i + (j > 0 ? s[j - 1] : 0)) {
    up = upper_bound(s.begin() + j, s.end(), i + (j > 0 ? s[j - 1] : 0));
    return up - low;
  }
  return 0;
}
int main() {
  int a;
  string st;
  cin >> a >> st;
  vector<long long> s(st.size());
  long long ans = 0;
  for (int i = 0; i < st.size(); i++) {
    s[i] = (int)(st[i] - '0');
    if (i > 0) s[i] += s[i - 1];
  }
  if (a == 0) {
    long long r = 0;
    for (int j = 0; j < st.size(); j++) {
      r += cnt(s, 0, j);
    }
    ans += r * st.size() * (st.size() + 1) - r * r;
    cout << ans << endl;
    return 0;
  }
  for (int i = 1; i * i <= a; i++) {
    if (a % i > 0) continue;
    long long r = 0, t = 0;
    for (int j = 0; j < st.size(); j++) {
      r += cnt(s, i, j);
    }
    for (int j = 0; j < st.size(); j++) {
      t += cnt(s, a / i, j);
    }
    if (i * i == a)
      ans += r * t;
    else
      ans += 2 * r * t;
  }
  cout << ans << endl;
  return 0;
}
