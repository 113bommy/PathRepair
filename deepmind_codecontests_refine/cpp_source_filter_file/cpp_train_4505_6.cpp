#include <bits/stdc++.h>
using namespace std;
using Node = std::pair<int, int>;
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
          auto it = st.begin();
          Node now = *it;
          if (now.second == 0) zero--;
          st.erase(it);
          sum2 -= now.first;
          st2.insert(now);
        }
      }
    }
    if (st.size() != cnt && st2.size() != 0) {
      auto it = --st2.end();
      Node now = *it;
      st.insert(now);
      if (now.second == 0) zero++;
      sum2 += now.first;
      st2.erase(it);
    }
    if (st.size() != 0 && st2.size() != 0) {
      auto it = st.begin();
      auto it2 = --st2.end();
      st.erase(it);
      st2.erase(it2);
      Node now1 = *it;
      Node now2 = *it2;
      if (now2.first > now1.first) {
        sum2 += now2.first - now1.first;
        if (now2.second == 0) zero++;
        if (now1.second == 0) zero--;
        st.insert(now2);
        st2.insert(now1);
      } else {
        st.insert(now1);
        st2.insert(now2);
      }
    }
    if (st.size() != 0 && zero == 0 && st.size() == cnt) {
      auto it1 = st.begin();
      Node now = *it1;
      st.erase(it1);
      sum2 -= now.first;
      if (st2.size() != 0) {
        auto it2 = --st2.end();
        Node now2 = *it2;
        st2.erase(it2);
        st.insert(now2);
        zero++;
        sum2 += now2.first;
      }
      st2.insert(now);
    }
    printf("%lld\n", sum1 + sum2);
  }
  return 0;
}
