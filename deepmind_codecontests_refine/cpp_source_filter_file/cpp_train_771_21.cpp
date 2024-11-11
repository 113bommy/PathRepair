#include <bits/stdc++.h>
using namespace std;
long long num[200020];
const long long inf = 1LL << 60;
struct pro {
  int sz;
  long long d, ci, pi;
  vector<long long> vect;
  void init() {
    sz = 0;
    ci = inf;
    pi = inf;
    vect.clear();
    d = 0;
  }
  int size() { return sz; }
  bool add(pair<int, long long> c) {
    if (ci == inf && c.second != -1) {
      ci = c.first;
      sz++;
      vect.push_back(c.second);
      return true;
    } else if (pi == inf && c.second != -1) {
      pi = ci;
      ci = c.first;
      if ((num[ci] - num[pi]) % (ci - pi) != 0)
        return false;
      else {
        d = (num[ci] - num[pi]) / (ci - pi);
        for (int i = vect.size() - 1; i >= 0; i--) {
          long long curr = num[ci] - (vect.size() - 1 - i) * d;
          if (curr <= 0) return false;
        }
        sz++;
        vect.push_back(c.second);
        return true;
      }
    } else if (c.second != -1) {
      if ((num[c.first] - num[ci]) % (c.first - ci) != 0 ||
          (num[c.first] - num[ci]) / (c.first - ci) != d) {
        return false;
      } else {
        pi = ci;
        ci = c.first;
        sz++;
        vect.push_back(c.second);
        return true;
      }
    } else {
      if (pi == inf) {
        sz++;
        vect.push_back(c.second);
        return true;
      }
      long long tmp = num[c.first - 1] + d;
      if (tmp <= 0) return false;
      num[c.first] = tmp;
      sz++;
      vect.push_back(c.second);
      return true;
    }
  }
};
int main() {
  int n;
  cin >> n;
  pro p;
  p.init();
  int res = 0;
  for (int i = 0; i < n; i++) cin >> num[i];
  for (int i = 0; i < n; i++) {
    bool rec = p.add(make_pair(i, num[i]));
    if (!rec) {
      p.init();
      p.add(make_pair(i, num[i]));
      res++;
    }
  }
  if (p.size()) res++;
  cout << res << endl;
}
