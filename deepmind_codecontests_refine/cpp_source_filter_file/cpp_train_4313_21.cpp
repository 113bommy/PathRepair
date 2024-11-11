#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
int n;
int b[333333];
vector<pair<int, int> > t;
int rv[333333];
struct Node {
  Node *lf;
  Node *rg;
  int l, r;
  int mx;
  Node() {
    lf = rg = 0;
    mx = 0;
  }
};
Node *root;
Node *buildTree(int from, int to) {
  Node *res = new Node();
  res->l = from;
  res->r = to;
  if (from != to) {
    res->lf = buildTree(from, (from + to) / 2);
    res->rg = buildTree((from + to) / 2 + 1, to);
  }
  return res;
}
void setValue(Node *curr, int pos, int val) {
  if (!curr) return;
  if (curr->l > pos || curr->r < pos) return;
  curr->mx = max(curr->mx, val);
  setValue(curr->lf, pos, val);
  setValue(curr->rg, pos, val);
}
int getBiggerL(Node *curr, int to, int val) {
  if (!curr) return -1;
  if (curr->mx <= val) return -1;
  if (curr->l > to) return -1;
  if (curr->l == curr->r) return curr->l;
  int p1 = getBiggerL(curr->rg, to, val);
  if (p1 != -1) return p1;
  return getBiggerL(curr->lf, to, val);
}
int getBiggerR(Node *curr, int from, int val) {
  if (!curr) return -1;
  if (curr->mx <= val) return -1;
  if (curr->r < from) return -1;
  if (curr->l == curr->r) return curr->l;
  int p1 = getBiggerR(curr->lf, from, val);
  if (p1 != -1) return p1;
  return getBiggerR(curr->rg, from, val);
}
double pw[111111];
int main() {
  pw[0] = 1;
  for (int i = (1); i < (111111); i++) pw[i] = pw[i - 1] / 2;
  cin >> n;
  for (int i = (0); i < (n); i++)
    scanf("%d", b + i), t.push_back(pair<int, int>(b[i], i));
  sort((t).begin(), (t).end());
  root = buildTree(0, n - 1);
  for (int i = (0); i < (n); i++) {
    rv[t[i].second] = i + 1;
    setValue(root, t[i].second, i + 1);
  }
  const int lim = 16;
  double sum = 0;
  vector<int> l, r;
  double den = 1. / n / n;
  l.reserve(lim), r.reserve(lim);
  for (int i = (0); i < (n); i++) {
    l.clear(), r.clear();
    int curr = i;
    while (1) {
      int pos = getBiggerL(root, curr - 1, rv[i]);
      if (pos == -1) {
        l.push_back(curr + 1);
        break;
      } else {
        l.push_back(curr - pos);
        curr = pos;
      }
      if (l.size() == lim) break;
    }
    curr = i;
    while (1) {
      int pos = getBiggerR(root, curr + 1, rv[i]);
      if (pos == -1) {
        r.push_back(n - curr);
        break;
      } else {
        r.push_back(pos - curr);
        curr = pos;
      }
      if (r.size() == lim) break;
    }
    for (int i1 = (0); i1 < (l.size()); i1++)
      for (int i2 = (0); i2 < (r.size()); i2++) {
        sum += b[i] * den * l[i1] * r[i2] * pw[i1 + i2 + 1];
      }
  }
  printf("%.10lf\n", sum);
  return 0;
}
