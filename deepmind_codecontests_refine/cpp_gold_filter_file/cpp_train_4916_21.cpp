#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
int f[N], n, x;
int occ[N];
vector<pair<int, int> > fac[N];
long long answer = 1000000000000000000ll;
struct node {
  map<int, node*> ch;
  map<int, int> chf;
  int cnt;
  long long ans;
  int factor;
  node() {
    ch.clear();
    chf.clear();
    ans = cnt = factor = 0;
  }
  void insert(vector<pair<int, int> >& v, int cnt) {
    if (!v.empty() && v.back().second == 0) v.pop_back();
    if (v.size() == 0) {
      this->cnt += cnt;
      return;
    }
    int val = v.back().first;
    if (!ch.count(val)) {
      ch[val] = new node();
      chf[val] = v.back().second;
    }
    v.back().second -= chf[val];
    ch[val]->insert(v, cnt);
  }
  void dfs1(long long number = 1) {
    factor = cnt;
    for (auto it : ch) {
      int val = it.first;
      node* nxt = it.second;
      int mul = chf[val];
      nxt->dfs1(number * val);
      ans += nxt->ans + 1ll * nxt->factor * mul;
      factor += nxt->factor;
    }
  }
  void getMin(long long pans, int pfactor, int pmul) {
    long long t1, t2;
    for (int tmul = pmul; tmul >= 0; tmul--) {
      t1 = pans + 1ll * (pmul - tmul) * pfactor;
      t2 = ans + 1ll * tmul * factor;
      answer = min(answer, t1 + t2);
    }
  }
  void dfs2(node* par = NULL, int pmul = 0, long long number = 1) {
    if (par) {
      long long pans = par->ans - (ans + 1ll * factor * pmul);
      int pfactor = par->factor - factor;
      getMin(pans, pfactor, pmul);
      ans += pans + 1ll * pfactor * pmul;
      factor += pfactor;
    } else {
      answer = ans;
    }
    for (auto it : ch) {
      int val = it.first;
      node* nxt = it.second;
      int mul = chf[val];
      nxt->dfs2(this, mul, number * val);
    }
  }
};
node* root = NULL;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    f[x]++;
  }
  for (int v = 2; v < N; v++) {
    int u = v;
    for (int i = 2; i * i <= v; i++) {
      if (u % i == 0) {
        int tmp = 0;
        while (u % i == 0) {
          tmp++;
          u /= i;
        }
        occ[i] += tmp;
      }
    }
    if (u > 1) {
      occ[u]++;
    }
    for (int i = 2; i < N; i++) {
      if (occ[i]) fac[v].push_back({i, occ[i]});
    }
  }
  root = new node();
  for (int i = 0; i < N; i++) {
    root->insert(fac[i], f[i]);
  }
  root->dfs1();
  root->dfs2();
  cout << answer << endl;
}
