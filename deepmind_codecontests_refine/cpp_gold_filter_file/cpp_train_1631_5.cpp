#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n;
vector<long long> b, p, r;
long long ans;
void process(bool f = 0) {
  if (f == 0) {
    if (p.size() == 1) {
      if (b.size()) {
        ans += p[0] - b[0];
      }
      if (r.size()) {
        ans += p[0] - r[0];
      }
    } else {
      long long v1 = 2 * (p.back() - p[p.size() - 2]);
      long long v2 = v1 / 2;
      if (b.size()) {
        long long mx = max(p.back() - b.back(), b.front() - p[p.size() - 2]);
        for (int i = 1; i < b.size(); i++) mx = max(mx, b[i] - b[i - 1]);
        v2 += p.back() - p[p.size() - 2] - mx;
      }
      if (r.size()) {
        long long mx = max(p.back() - r.back(), r.front() - p[p.size() - 2]);
        for (int i = 1; i < r.size(); i++) mx = max(mx, r[i] - r[i - 1]);
        v2 += p.back() - p[p.size() - 2] - mx;
      }
      ans += min(v1, v2);
    }
  } else {
    if (p.size()) {
      if (b.size()) ans += b.back() - p.back();
      if (r.size()) ans += r.back() - p.back();
    } else {
      if (b.size()) ans += b.back() - b.front();
      if (r.size()) ans += r.back() - r.front();
    }
  }
  b.clear(), r.clear();
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char ch;
    long long pos;
    scanf("%I64d %c", &pos, &ch);
    if (ch == 'P') {
      p.push_back(pos);
      process();
    } else if (ch == 'B') {
      b.push_back(pos);
    } else if (ch == 'R') {
      r.push_back(pos);
    }
  }
  process(1);
  printf("%I64d", ans);
}
