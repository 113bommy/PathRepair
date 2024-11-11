#include <bits/stdc++.h>
using namespace std;
struct Node {
  int id, v;
  bool operator<(const Node &rhs) const {
    if (v == rhs.v) return id > rhs.id;
    return v > rhs.v;
  }
};
int64_t sum1, sum2;
int zero;
int cnt;
set<Node> st;
set<Node> st2;
int main() {
  int n;
  scanf("%d", &n);
  sum1 = 0;
  sum2 = 0;
  cnt = 0;
  zero = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (y > 0) {
      if (x == 1) cnt++;
      sum1 += y;
      st2.insert({x, y});
    } else {
      y = -y;
      sum1 -= y;
      auto it = st2.find({x, y});
      if (it != st2.end()) {
        st2.erase(it);
      } else {
        it = st.find({x, y});
        st.erase(it);
        if (x == 0) zero--;
        sum2 -= y;
      }
      if (x == 1) {
        cnt--;
        if (st.size() != 0) {
          auto it = --st.end();
          Node now = *it;
          if (now.id == 0) zero--;
          st.erase(it);
          sum2 -= now.v;
          st2.insert(now);
        }
      }
    }
    if (st.size() != cnt && st2.size() != 0) {
      auto it = st2.begin();
      Node now = *it;
      st.insert(now);
      if (now.id == 0) zero++;
      sum2 += now.v;
      st2.erase(it);
    }
    if (st.size() != cnt && st2.size() != 0) {
      auto it = --st.end();
      auto it2 = st2.begin();
      st.erase(it);
      st2.erase(it2);
      Node now1 = *it;
      Node now2 = *it2;
      if (now2.v > now1.v) {
        sum2 += now2.v - now1.v;
        if (now2.id == 0) zero++;
        if (now1.id == 0) zero--;
        st.insert(now2);
        st2.insert(now1);
      } else {
        st.insert(now1);
        st2.insert(now2);
      }
    }
    if (st.size() != 0 && zero == 0 && st.size() == cnt) {
      auto it1 = --st.end();
      Node now = *it1;
      st.erase(it1);
      sum2 -= now.v;
      if (st2.size() != 0) {
        auto it2 = st2.begin();
        Node now2 = *it2;
        st2.erase(it2);
        st.insert(now2);
        zero++;
        sum2 += now2.v;
      }
      st2.insert(now);
    }
    printf("%lld\n", sum1 + sum2);
  }
  return 0;
}
