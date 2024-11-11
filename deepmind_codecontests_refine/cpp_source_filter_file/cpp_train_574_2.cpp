#include <bits/stdc++.h>
using namespace std;
int n;
int k;
map<long long int, vector<long long int> > ins;
map<long long int, vector<long long int> > del;
long long int ys[100002 * 5];
int ys_size;
vector<long long int> xs;
long long int pr_calc[100002 * 7];
long long int bet_pr_calc[100002 * 7];
int cnt[100002 * 7];
long long int ans[100002];
void ADD(int x) {
  ys[ys_size] = x;
  ys_size++;
  ys[ys_size] = x + k - 1;
  ys_size++;
  ys[ys_size] = x - k + 1;
  ys_size++;
}
void calc(int b, int X, int add) {
  int lef = ys[b] - k + 1;
  int rig = ys[b] + k - 1;
  lef = lower_bound(ys, ys + ys_size, lef) - ys;
  rig = lower_bound(ys, ys + ys_size, rig) - ys;
  int L = lef;
  int sum = 0;
  for (int i = lef; i <= b; i++) {
    sum += (int)(cnt[i]);
  }
  if (sum) {
    ans[sum] += (X - pr_calc[b]);
  }
  pr_calc[b] = X;
  for (int i = b + 1; i <= rig; i++) {
    int be = ys[i - 1] + 1;
    while (be < ys[i]) {
      while (ys[L] + k <= be) {
        sum -= cnt[L];
        L++;
      }
      if (sum) ans[sum] += (X - bet_pr_calc[i]);
      be++;
    }
    while (ys[L] + k <= ys[i]) {
      sum -= cnt[L];
      L++;
    }
    sum += cnt[i];
    if (sum) {
      ans[sum] += (X - pr_calc[i]);
    }
    bet_pr_calc[i] = X;
    pr_calc[i] = X;
  }
  cnt[b] += add;
  return;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ins[x].push_back(y);
    del[x + k].push_back(y);
    ADD(y);
    xs.push_back(x);
    xs.push_back(x + k);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  sort(ys, ys + ys_size);
  ys_size = unique(ys, ys + ys_size) - ys;
  for (int i = 0; i < ys_size; i++) {
    pr_calc[i] = bet_pr_calc[i] = INT_MIN;
  }
  for (auto it = ins.begin(); it != ins.end(); it++) {
    vector<long long int> &v = (*it).second;
    for (int i = 0; i < v.size(); i++) {
      v[i] = lower_bound(ys, ys + ys_size, v[i]) - ys;
    }
  }
  for (auto it = del.begin(); it != del.end(); it++) {
    vector<long long int> &v = (*it).second;
    for (int i = 0; i < v.size(); i++) {
      v[i] = lower_bound(ys, ys + ys_size, v[i]) - ys;
    }
  }
  for (int i = 0; i < xs.size(); i++) {
    if (ins.count(xs[i])) {
      vector<long long int> &v = ins[xs[i]];
      for (int j = 0; j < v.size(); j++) {
        calc(v[j], xs[i], 1);
      }
    }
    if (del.count(xs[i])) {
      vector<long long int> &v = del[xs[i]];
      for (int j = 0; j < v.size(); j++) {
        calc(v[j], xs[i], -1);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%d", ans[i]);
  }
  puts("");
  return 0;
}
