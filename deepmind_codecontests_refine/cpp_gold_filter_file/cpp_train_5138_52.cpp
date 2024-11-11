#include <bits/stdc++.h>
const int N = 5010;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
using namespace std;
queue<long long> que[N];
struct data {
  long long k;
  int id;
  data();
  data(long long _k, int _id) : k(_k), id(_id) {}
  bool operator<(const data &r) const {
    if (k == r.k) return id < r.id;
    return k < r.k;
  }
};
vector<data> vt;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int k;
    long long a, x, y, m;
    cin >> k >> a >> x >> y >> m;
    for (int j = 0; j < k; j++) {
      que[i].push(a);
      a = (a * x + y) % m;
    }
  }
  set<data> st;
  for (int i = 0; i < n; i++) st.insert(data(que[i].front(), i));
  long long pre = inf;
  int ret = 0;
  while (st.size()) {
    set<data>::iterator it;
    data tmp = data(pre, -1);
    it = st.insert(tmp).first;
    it++;
    if (it == st.end()) {
      set<data>::iterator bg = st.begin();
      data hh = *bg;
      vt.push_back(hh);
      st.erase(*bg);
      pre = hh.k;
      ret++;
      que[hh.id].pop();
      if (que[hh.id].size()) st.insert(data(que[hh.id].front(), hh.id));
    } else {
      data hh = *it;
      vt.push_back(hh);
      st.erase(*it);
      pre = hh.k;
      que[hh.id].pop();
      if (que[hh.id].size()) st.insert(data(que[hh.id].front(), hh.id));
    }
    st.erase(tmp);
  }
  cout << ret - 1 << endl;
  int sz = vt.size();
  for (int i = 0; i < sz; i++) cout << vt[i].k << " " << vt[i].id + 1 << endl;
  return 0;
}
