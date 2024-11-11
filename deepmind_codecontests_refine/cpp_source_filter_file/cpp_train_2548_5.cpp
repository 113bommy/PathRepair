#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9;
const int SIZE = 1e6 + 5;
const long long INF = 1LL << 55;
const double eps = 1e-10;
multiset<int> adj[100009];
vector<int> ec;
vector<int> od;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (m); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    adj[x].insert(y);
    adj[y].insert(x);
  }
  for (int i = 0; i < (m); ++i) {
    if (((int)(adj[i]).size()) % 2) od.push_back(i);
  }
  for (int i = 0; i < (((int)(od).size()) / 2); ++i) {
    adj[od[i]].insert(od[((int)(od).size()) - 1 - i]);
    adj[od[((int)(od).size()) - 1 - i]].insert(od[i]);
    m++;
  }
  if (m % 2) {
    adj[0].insert(0);
    m++;
    adj[0].insert(0);
  }
  stack<int> st;
  int cur = 0;
  while (true) {
    if (((int)(adj[cur]).size()) == 0) {
      if (((int)(st).size()) == 0) break;
      ec.push_back(cur);
      cur = st.top();
      st.pop();
    } else {
      int ncur = *adj[cur].begin();
      adj[cur].erase(adj[cur].begin());
      adj[ncur].erase(adj[ncur].find(cur));
      st.push(cur);
      cur = ncur;
    }
  }
  printf("%d\n", m);
  ec.push_back(0);
  for (int i = 0; i < (((int)(ec).size()) - 1); ++i) {
    if (i % 2)
      printf("%d %d\n", ec[i] + 1, ec[i + 1] + 1);
    else
      printf("%d %d\n", ec[i + 1] + 1, ec[i] + 1);
  }
}
