#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = (int)2e5 + 10;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
int n;
vector<int> a, b;
vector<int> firstBet, lastBet;
vector<vector<int> > pos;
struct cmp {
  bool operator()(int a, int b) { return lastBet[a] < lastBet[b]; }
};
void filling() {
  a.resize(n);
  b.resize(n);
  pos.resize(n);
  firstBet.assign(n, inf);
  lastBet.assign(n, -inf);
}
int main() {
  scanf("%d", &n);
  filling();
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &b[i]);
    a[i]--;
    firstBet[a[i]] = min(firstBet[a[i]], i);
    lastBet[a[i]] = max(lastBet[a[i]], i);
    pos[a[i]].push_back(i);
  }
  set<int, cmp> st;
  for (int i = 0; i < n; i++) {
    st.insert(a[i]);
  }
  int query;
  scanf("%d", &query);
  while (query--) {
    int cnt;
    scanf("%d", &cnt);
    vector<int> dead;
    for (int i = 0; i < cnt; i++) {
      int id;
      scanf("%d", &id);
      id--;
      if (lastBet[id] != -inf) {
        dead.push_back(id);
        st.erase(id);
      }
    }
    if (st.empty()) {
      printf("0 0\n");
      for (const int &x : dead) {
        st.insert(x);
      }
      continue;
    }
    auto it = st.end();
    it--;
    int winnerPos = *it;
    if ((int)(st.size()) == 1) {
      printf("%d %d\n", winnerPos + 1, b[firstBet[winnerPos]]);
      for (const int &x : dead) {
        st.insert(x);
      }
      continue;
    }
    it--;
    int prev = *it;
    int left = -1, right = (int)(pos[winnerPos].size()) - 1;
    while (right - left > 1) {
      int mid = left + (right - left) / 2;
      if (pos[winnerPos][mid] > lastBet[prev])
        right = mid;
      else
        left = mid;
    }
    printf("%d %d\n", winnerPos + 1, b[pos[winnerPos][right]]);
    for (const int &x : dead) {
      st.insert(x);
    }
  }
  return 0;
}
