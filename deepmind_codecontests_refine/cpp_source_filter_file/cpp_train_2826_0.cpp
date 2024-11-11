#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node {
  int x;
  int id;
  int flag;
  Node() {}
  Node(int x, int id, int flag) : x(x), id(id), flag(flag) {}
};
int a[maxn * 4], s[maxn], p[maxn], inc[maxn], b[maxn], treea[maxn * 4],
    treeb[maxn * 4], push_back[maxn];
int ans[maxn];
vector<Node> ft;
vector<int> st;
map<int, int> idx;
int n, m;
int sum1[500010], sum2[500010];
int get_idx(int t) { return idx[t]; }
void add1(int t, int flag) {
  for (; t <= 4 * n; t += t & -t) {
    sum1[t] += flag;
  }
}
void add2(int t, int flag) {
  for (; t <= 4 * n; t += t & -t) {
    sum2[t] += flag;
  }
}
int getid(int x) { return idx[x]; }
int get1(int t) {
  int ret = 0;
  while (t > 0) {
    ret += sum1[t];
    t -= t & -t;
  }
  return ret;
}
int get2(int t) {
  int ret = 0;
  while (t > 0) {
    ret += sum2[t];
    t -= t & -t;
  }
  return ret;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &inc[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &push_back[i]);
  for (int i = 1; i <= n; i++) {
    ft.push_back(Node(p[i], i, 0));
    ft.push_back(Node(s[i], i, 2));
    st.push_back(-(b[i] + p[i] - 1));
    st.push_back(-(b[i] - p[i]));
  }
  for (int i = 1; i <= m; i++) {
    ft.push_back(Node(inc[i], i, 1));
    st.push_back(-(push_back[i] - inc[i]));
    st.push_back(-(inc[i] + push_back[i]));
  }
  auto cmp = [&](const Node &a, const Node &b) {
    return a.x < b.x || (a.x == b.x && a.flag < b.flag);
  };
  sort(ft.begin(), ft.end(), cmp);
  sort(st.begin(), st.end());
  int pos = unique(st.begin(), st.end()) - st.begin();
  for (int i = 0; i < pos; ++i) {
    idx[-st[i]] = i + 1;
  }
  for (int i = 0; i < ft.size(); i++) {
    Node now = ft[i];
    if (now.flag == 0) {
      add1(getid(b[now.id] - p[now.id]), 1);
      add2(getid(p[now.id] + b[now.id] - 1), -1);
    } else if (now.flag == 1) {
      ans[now.id] = get1(getid(push_back[now.id] - inc[now.id])) +
                    get2(getid(inc[now.id] + push_back[now.id]));
    } else if (now.flag == 2) {
      add1(getid(b[now.id] - p[now.id]), -1);
      add2(getid(p[now.id] + b[now.id] - 1), 1);
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
