#include <bits/stdc++.h>
using namespace std;
long long skill[100010];
vector<pair<long long, long long> > adds[100010];
pair<long long, long long> planch[100010];
int type[100010];
struct event {
  int i;
  long long p, q;
};
vector<event> ops;
bool compa1(const event a, const event b) {
  if (a.p * b.q != a.q * b.p) return a.p * b.q > a.q * b.p;
  return a.i < b.i;
}
vector<pair<int, int> > ans;
int main() {
  int k, n, m;
  cin >> k >> n >> m;
  for (int i = 0; i < (int)(k); ++i) cin >> skill[i];
  for (int i = 0; i < (int)(n); ++i) {
    long long t, j, b;
    cin >> t >> j >> b;
    j--;
    if (t == 1) {
      if (b > planch[j].first) {
        planch[j].first = b;
        planch[j].second = i;
      }
    }
    if (t == 2) {
      adds[j].push_back(make_pair(b, i));
    }
    if (t == 3) {
      event ne;
      ne.i = i;
      ne.p = b - 1;
      ne.q = 1;
      ops.push_back(ne);
    }
    type[i] = t;
  }
  for (int i = 0; i < (int)(k); ++i) {
    if (planch[i].first > skill[i])
      adds[i].push_back(
          make_pair(planch[i].first - skill[i], planch[i].second));
    sort(adds[i].begin(), adds[i].end());
    reverse(adds[i].begin(), adds[i].end());
    int as = adds[i].size();
    for (int j = 0; j < (int)(as); ++j) {
      event ne;
      ne.i = adds[i][j].second;
      ne.p = adds[i][j].first;
      ne.q = skill[i];
      ops.push_back(ne);
      skill[i] += adds[i][j].first;
    }
  }
  sort(ops.begin(), ops.end(), compa1);
  int l = min((int)ops.size(), m);
  for (int i = 0; i < (int)(l); ++i) {
    ans.push_back(make_pair(type[ops[i].i], ops[i].i));
  }
  cout << l << endl;
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int)(l); ++i) {
    if (i) cout << " ";
    cout << ans[i].second + 1;
  }
  cout << endl;
  return 0;
}
