#include <bits/stdc++.h>
using namespace std;
struct tree_node {
  set<int>* data;
  tree_node() { this->data = new set<int>(); }
};
int log2(int n) {
  int log = 0;
  while (n > 1) {
    log++;
    n /= 2;
  }
  return log;
}
bool isPow2(int n) { return n != 0 && ((1 << log2(n)) == n); }
int getRightIndex(int k) { return k + log2(k) + 1; }
int getParent(int k, int level) {
  int i = 1;
  int j = level * level;
  int d;
  int right;
  bool pow2;
  while (j - i > 1) {
    d = (i + j) / 2;
    pow2 = isPow2(d);
    right = getRightIndex(d);
    if (k == right || (pow2 && k == right - 1)) return d;
    if (right < k)
      i = d;
    else
      j = d;
  }
  right = getRightIndex(j);
  pow2 = isPow2(j);
  if (k == right || (pow2 && k == right - 1)) return j;
  return i;
}
int min(int x, int y) { return x < y ? x : y; }
int max(int x, int y) { return x > y ? x : y; }
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<int>** arrLeft = new vector<int>*[n];
  vector<int>** arrRight = new vector<int>*[n];
  vector<int>** arrX = new vector<int>*[n];
  for (int i = 0; i < n; i++) {
    arrLeft[i] = new vector<int>(0);
    arrRight[i] = new vector<int>(0);
    arrX[i] = new vector<int>(0);
  }
  set<int> s = set<int>();
  int cmd, t, l, r, x, v;
  int rangeLeft, rangeRight;
  int left, right;
  for (int i = 0; i < m; i++) {
    cin >> cmd;
    if (cmd == 1) {
      cin >> t;
      t--;
      cin >> l;
      cin >> r;
      cin >> x;
      arrLeft[t]->push_back(l);
      arrRight[t]->push_back(r);
      arrX[t]->push_back(x);
    } else {
      cin >> t;
      t--;
      cin >> v;
      s.clear();
      rangeLeft = v;
      rangeRight = v;
      for (int it = t; it < n; it++) {
        for (int j = 0; j < arrLeft[it]->size(); j++) {
          left = arrLeft[it]->at(j);
          right = arrRight[it]->at(j);
          left = max(left, rangeLeft);
          right = min(rangeRight, right);
          if (left <= right) {
            s.insert(arrX[it]->at(j));
          }
        }
        if (isPow2(v))
          rangeLeft = getRightIndex(rangeLeft) - 1;
        else
          rangeLeft = getRightIndex(rangeLeft);
        rangeRight = getRightIndex(rangeRight);
      }
      cout << s.size() << endl;
    }
  }
  return 0;
}
