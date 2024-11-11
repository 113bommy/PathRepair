#include <bits/stdc++.h>
using namespace std;
long long val[100050];
int degree[100050], par[100050];
struct cmp {
  bool operator()(int a, int b) {
    if (val[a] != val[b]) return val[a] < val[b];
    return a < b;
  }
};
set<int, cmp> son[100050];
multiset<long long> overall;
long long t[100050];
int n, q;
long long val_oth(int pos) { return t[pos] / (degree[pos] + 2); }
long long val_sel(int pos) {
  return t[pos] - (degree[pos] + 1) * (t[pos] / (degree[pos] + 2));
}
void ins(int pos) {
  if (!son[pos].empty()) {
    long long fuck = val[*son[pos].begin()] + val_oth(pos);
    overall.insert(fuck);
  }
  if (son[pos].size() >= 2) {
    long long fuck = val[*(--son[pos].end())] + val_oth(pos);
    overall.insert(fuck);
  }
}
void era(int pos) {
  if (!son[pos].empty()) {
    long long fuck = val[*son[pos].begin()] + val_oth(pos);
    overall.erase(overall.find(fuck));
  }
  if (son[pos].size() >= 2) {
    long long fuck = val[*(--son[pos].end())] + val_oth(pos);
    overall.erase(overall.find(fuck));
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%lld", &t[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &par[i]), son[par[i]].insert(i), degree[par[i]]++;
  for (int i = 1; i <= n; ++i) {
    son[par[i]].erase(i);
    for (auto u : son[i]) val[i] += val_oth(u);
    val[i] += val_sel(i);
    son[par[i]].insert(i);
  }
  for (int i = 1; i <= n; ++i) ins(i);
  for (int i = 1; i <= q; ++i) {
    int typ;
    scanf("%d", &typ);
    if (typ == 1) {
      int a, b;
      scanf("%d%d", &a, &b);
      set<int> st, more;
      st.insert(a), st.insert(b), st.insert(par[a]), st.insert(par[b]),
          st.insert(par[par[a]]);
      more = st;
      more.insert(par[par[par[a]]]), more.insert(par[par[b]]);
      for (auto i : more) era(i);
      for (auto i : st) son[par[i]].erase(i);
      for (int cur = -1; cur <= 1; cur += 2) {
        for (auto i : st) {
          val[i] += cur * val_sel(i);
          for (auto j : st)
            if (par[j] == i) val[i] += cur * val_oth(j);
        }
        if (cur == -1) {
          degree[par[a]]--;
          par[a] = b;
          degree[par[a]]++;
        }
      }
      for (auto i : st) son[par[i]].insert(i);
      for (auto i : more) ins(i);
    } else if (typ == 2) {
      int pos;
      scanf("%d", &pos);
      printf("%lld\n", val[pos] + val_oth(par[pos]));
    } else {
      printf("%lld %lld\n", *overall.begin(), *(--overall.end()));
    }
  }
}
