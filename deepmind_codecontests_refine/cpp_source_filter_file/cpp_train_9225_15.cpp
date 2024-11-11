#include <bits/stdc++.h>
using namespace std;
int cnt(deque<pair<int, int> > &q) {
  int ans = 0;
  for (int i = 0; i < q.size(); i++) {
    ans += q[i].second;
  }
  return ans;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int m, k;
  int n, x;
  cin >> n >> k >> m;
  deque<pair<int, int> > st, mi, en;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (mi.empty()) {
      mi.push_back(make_pair(x, 1));
    } else if (mi.back().first == x) {
      mi.back().second++;
    } else {
      mi.push_back(make_pair(x, 1));
    }
    if (mi.back().second % k == 0) mi.pop_back();
  }
  st = mi;
  en = mi;
  if (m == 1) {
    cout << cnt(mi) << endl;
  } else if (m == 2) {
    int ans = 2 * cnt(st);
    while (true) {
      if (st.empty() || en.empty()) break;
      int tmp = st.back().second + en.front().second;
      if (st.back().first != en.front().second)
        break;
      else if (tmp % k == 0) {
        st.pop_back();
        en.pop_front();
        ans -= tmp;
      } else {
        ans -= (tmp - tmp % k);
        break;
      }
    }
    cout << ans << endl;
  } else {
    long long int ans = m * cnt(st);
    while (mi.size() > 1) {
      int tmp = st.back().second + mi.front().second;
      if (st.back().first == mi.front().first && tmp % k == 0) {
        ans -= (m - 1) * tmp;
        st.pop_back();
        mi.pop_front();
        mi.pop_back();
        en.pop_front();
      } else if (st.back().first == mi.front().first) {
        ans -= (m - 1) * (tmp - tmp % k);
        cout << ans << endl;
        return 0;
      } else {
        cout << ans << endl;
        return 0;
      }
    }
    if (mi.size() == 1) {
      long long int tmp = m * mi.back().second;
      if (tmp % k == 0) {
        ans -= tmp;
        mi.pop_back();
        st.pop_back();
        en.pop_front();
      } else {
        ans -= (tmp - tmp % k);
        cout << ans << endl;
        return 0;
      }
    }
    while (!st.empty() && !en.empty()) {
      int tmp = st.back().second + en.front().second;
      if (st.back().first == en.front().first) {
        if (tmp % k == 0) {
          ans -= tmp;
          st.pop_back();
          en.pop_front();
        } else {
          ans -= (tmp - tmp % k);
          cout << ans << endl;
          return 0;
        }
      } else {
        cout << ans << endl;
        return 0;
      }
    }
    cout << ans << endl;
  }
}
