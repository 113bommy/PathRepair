#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100001];
int arrdone = 0, nodeseen = 0;
struct node {
  int l, r;
  int id, maxpay;
  double prob;
  int depth;
  vector<double> dist;
  vector<int> child;
  void prelim();
  void fillProb(int low, int high);
  void print(int);
  bool operator<(node const &nd) const {
    return l == nd.l ? r > nd.r : l < nd.l;
  }
};
node reco[5001];
void node::print(int indent) {
  for (int i = 0; i < indent; ++i) cout << ' ';
  cout << l << ' ' << r << ' ' << depth << ' ' << maxpay << ' ' << prob << endl;
  for (int i = 0; i < indent; ++i) cout << ' ';
  for (int i = 0; i < dist.size(); ++i) cout << dist[i] << ' ';
  cout << endl;
  for (int i = 0; i < child.size(); ++i) reco[child[i]].print(indent + 1);
}
void node::prelim() {
  maxpay = 0;
  while (arrdone < l) arrdone++;
  while (arrdone < r && arrdone < reco[id + 1].l)
    maxpay = max(maxpay, a[arrdone++]);
  depth = 1;
  ++nodeseen;
  while (reco[nodeseen].l < r) {
    child.push_back(nodeseen);
    reco[nodeseen].prelim();
    depth = max(depth, reco[child.back()].depth + 1);
    maxpay = max(maxpay, reco[child.back()].maxpay);
  }
  while (arrdone < r) maxpay = max(maxpay, a[arrdone++]);
}
void node::fillProb(int low, int high) {
  dist.resize(high - low + 1, 0);
  for (int i = 0; i < child.size(); ++i) reco[child[i]].fillProb(low - 1, high);
  for (int i = max(maxpay + 1 - (low - 1), 0); i < high - (low - 1); ++i) {
    dist[i] = 1;
    for (int j = 0; j < child.size(); ++j) dist[i] *= reco[child[j]].dist[i];
  }
  for (int i = 0; i < high - low; ++i)
    dist[i] = prob * dist[i] + (1 - prob) * dist[i + 1];
  dist.pop_back();
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  reco[0].l = 0;
  reco[0].r = n;
  reco[0].prob = 0;
  ++q;
  for (int i = 1; i < q; ++i) {
    cin >> reco[i].l >> reco[i].r >> reco[i].prob;
    --reco[i].l;
  }
  sort(reco + 1, reco + q);
  reco[q].l = n;
  for (int i = 0; i < q; ++i) reco[i].id = i;
  reco[0].prelim();
  reco[0].fillProb(reco[0].maxpay + 1, reco[0].maxpay + reco[0].depth + 1);
  double res = reco[0].maxpay;
  for (int i = 0; i < reco[0].depth; ++i) res += 1 - reco[0].dist[i];
  cout << setprecision(15) << res << endl;
  return 0;
}
