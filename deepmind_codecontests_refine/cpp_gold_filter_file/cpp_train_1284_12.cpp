#include <bits/stdc++.h>
using namespace std;
void ASS(bool bb) {
  if (!bb) {
    ++*(int*)0;
  }
}
#pragma comment(linker, "/STACK:106777216")
struct S2 {
  unsigned a[4];
  S2() { memset(a, 0, sizeof(a)); }
  void set(int x) { a[x >> 5] |= 1 << (x & 31); }
  bool operator<(const S2& s) const { return memcmp(a, s.a, sizeof(a)) < 0; }
};
struct S {
  int x;
  long long m;
  S2 s2;
  bool operator<(const S& s) const { return x > s.x; }
};
int main() {
  int n, k, t;
  cin >> n >> k >> t;
  vector<S> v;
  for (int i = 0; i < (int)(k); i++) {
    S s;
    int x, y;
    cin >> x >> y >> s.x;
    x--;
    y--;
    s.m = (1LL << x) + (1LL << (y + n));
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  priority_queue<S> q;
  {
    S s;
    s.m = 0;
    s.x = 0;
    q.push(s);
  }
  map<S2, int> st;
  vector<int> all;
  while (q.size() > 0 && st.size() < t + 10000) {
    if (q.empty()) break;
    S s = q.top();
    q.pop();
    all.push_back(s.x);
    for (int i = 0; i < (int)(k); i++)
      if ((s.m & v[i].m) == 0) {
        S t = s;
        t.m |= v[i].m;
        t.x += v[i].x;
        t.s2.set(i);
        int& g = st[t.s2];
        if (g == 0) {
          g = 1;
          q.push(t);
        }
      }
  }
  while (!q.empty()) {
    all.push_back(q.top().x);
    q.pop();
  }
  sort(all.begin(), all.end());
  cout << all[t - 1] << endl;
  return 0;
}
