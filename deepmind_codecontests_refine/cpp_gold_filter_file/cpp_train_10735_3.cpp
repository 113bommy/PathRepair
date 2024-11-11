#include <bits/stdc++.h>
using namespace std;
struct Data {
  long long time;
  long long width;
  long long start;
  long long free;
};
struct Node {
  long long s, e, m;
  Data d;
  Node *l, *r;
  Node(long long _s, long long _e) {
    s = _s;
    e = _e;
    d.width = e - s + 1;
    d.start = 0;
    d.time = 0;
    d.free = 0;
    m = (s + e) / 2;
    if (s == e) {
      return;
    }
    l = new Node(s, m);
    r = new Node(m + 1, e);
  }
  Data combine(Data l, Data r) {
    Data ans;
    ans.width = l.width + r.width;
    if (r.time == 0 && l.time == 0) {
      ans.time = 0;
      ans.start = 0;
      ans.free = 0;
      return ans;
    }
    if (r.time == 0) {
      ans.start = l.start;
      ans.time = l.time;
      ans.free = l.free;
    } else if (l.time == 0) {
      ans.start = l.width + r.start;
      ans.time = r.time;
      ans.free = r.free;
    } else {
      ans.start = l.start;
      ans.free = l.free + r.free;
      long long propstart = l.start + l.time;
      if (propstart <= l.width + r.start) {
        ans.time = l.width + r.start + r.time - l.start;
        ans.free += (l.width + r.start) - propstart;
      } else {
        long long overlap = propstart - (l.width + r.start);
        if (overlap <= r.free) {
          ans.time = l.width + r.start + r.time - l.start;
          ans.free -= overlap;
        } else {
          ans.time = l.time + r.time - r.free;
          ans.free = l.free;
        }
      }
    }
    return ans;
  }
  void update(long long pos, long long val) {
    if (s == e) {
      assert(s == pos);
      d.start = 0;
      d.width = 1;
      d.time = val;
      return;
    }
    if (pos <= m) {
      l->update(pos, val);
    } else {
      r->update(pos, val);
    }
    d = combine(l->d, r->d);
  }
  Data query(long long a, long long b) {
    if (s == a && e == b) {
      return d;
    }
    if (b <= m) {
      return l->query(a, b);
    } else if (m < a) {
      return r->query(a, b);
    } else {
      return combine(l->query(a, m), r->query(m + 1, b));
    }
  }
};
Node *root;
int main() {
  long long q;
  cin >> q;
  root = new Node(0, 1000009);
  vector<long long> times(q, 0);
  for (long long i = 0; i < q; i++) {
    char c;
    cin >> c;
    if (c == '+') {
      long long t, d;
      cin >> t >> d;
      root->update(t - 1, d);
      times[i] = t;
    } else if (c == '-') {
      long long index;
      cin >> index;
      index--;
      root->update(times[index] - 1, 0);
    } else if (c == '?') {
      long long t;
      cin >> t;
      long long ttaken =
          (root->query(0, t - 1)).start + (root->query(0, t - 1)).time;
      cout << max(0LL, ttaken - t + 1) << endl;
    }
  }
  return 0;
}
