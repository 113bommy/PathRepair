#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433832795;
unsigned long long mod = 1000 * 1000 * 1000 + 7;
int INF = 1000 * 1000 * 1000;
vector<int> v;
class node {
 public:
  node() {
    left = right = NULL;
    addVal = 0;
  }
  int from, to;
  int minVal, minPos, addVal;
  node *left, *right;
  void build(int i, int j) {
    from = i;
    to = j;
    if (i == j) {
      minVal = v[i];
      minPos = i;
    } else {
      int mid = (i + j) / 2;
      if (i <= mid) {
        left = new node();
        left->build(i, mid);
      }
      if (mid + 1 <= j) {
        right = new node();
        right->build(mid + 1, j);
      }
      if (left->minVal < right->minVal) {
        minVal = left->minVal;
        minPos = left->minPos;
      } else {
        minVal = right->minVal;
        minPos = right->minPos;
      }
    }
  }
  pair<int, int> getMin(int i, int j) {
    if (i <= from && to <= j) return make_pair(minVal + addVal, minPos);
    if (i > to || j < from) return make_pair(INF, -1);
    pair<int, int> r1 = left->getMin(i, j);
    pair<int, int> r2 = right->getMin(i, j);
    r1.first += addVal;
    r2.first += addVal;
    return min(r1, r2);
  }
  void add(int i, int j, int val) {
    if (i <= from && to <= j) {
      addVal += val;
      return;
    }
    if (i > to || j < from) return;
    left->add(i, j, val);
    right->add(i, j, val);
    return;
  }
} * root;
int main() {
  int n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  root = new node();
  root->build(0, n - 1);
  queue<pair<int, int> > q;
  q.push(make_pair(0, n - 1));
  vector<pair<int, int> > res;
  while (!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();
    pair<int, int> r = root->getMin(top.first, top.second);
    for (int i = 0; i < r.first; i++)
      res.push_back(make_pair(top.first, top.second));
    root->add(top.first, top.second, -r.first);
    if (top.first <= r.second - 1) q.push(make_pair(top.first, r.second - 1));
    if (r.second + 1 <= top.second) q.push(make_pair(r.second + 1, top.second));
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++)
    cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
  return 0;
}
