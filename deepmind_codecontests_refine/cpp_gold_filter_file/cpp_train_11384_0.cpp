#include <bits/stdc++.h>
using namespace std;
vector<pair<char, pair<int, int> > > V;
set<int> S;
set<int> B[200005];
int A[200005];
pair<int, int> tree[800005];
void update(int x, int y, int l, int r, int node, bool flag) {
  if (l > x || r < x) {
    return;
  }
  if (l == r && l == x) {
    if (flag) {
      tree[node].first = max(tree[node].first, y);
      tree[node].second = x;
    } else {
      tree[node].first = y;
      tree[node].second = x;
    }
    return;
  }
  int le = (node << 1);
  int ri = (node << 1) ^ 1;
  update(x, y, l, ((l + r) >> 1), le, flag);
  update(x, y, (((l + r) >> 1) + 1), r, ri, flag);
  if (tree[le].first >= tree[ri].first) {
    tree[node] = tree[le];
  } else
    tree[node] = tree[ri];
}
pair<int, int> query(int a, int b, int l, int r, int value, int node) {
  if (l > b || r < a) {
    return make_pair(-1, -1);
  }
  if (tree[node].first <= value) return make_pair(-1, -1);
  if (l >= a && r <= b && l == r) {
    if (tree[node].first > value) {
      return tree[node];
    }
    return make_pair(-1, -1);
  }
  int le = (node << 1);
  int ri = (node << 1) ^ 1;
  pair<int, int> lef = query(a, b, l, ((l + r) >> 1), value, le);
  if (lef.first != -1) {
    return lef;
  }
  return query(a, b, (((l + r) >> 1) + 1), r, value, ri);
}
unordered_map<int, int> M;
int iM[200005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 800000; ++i) tree[i] = make_pair(-1, -1);
  getchar();
  for (int i = 1; i <= n; ++i) {
    pair<int, int> temp;
    char s;
    s = getchar();
    if (s == 'f') {
      s = getchar();
      s = getchar();
      s = getchar();
      s = 'f';
    }
    if (s == 'r') {
      s = getchar();
      s = getchar();
      s = getchar();
      s = getchar();
      s = getchar();
      s = 'r';
    }
    if (s == 'a') {
      s = getchar();
      s = getchar();
      s = 'a';
    }
    scanf(" %d %d", &temp.first, &temp.second);
    V.push_back(make_pair(s, temp));
    S.insert(temp.first);
    s = getchar();
  }
  int lindex = 1;
  set<int>::iterator it = S.begin();
  while (it != S.end()) {
    M[*it] = lindex;
    iM[lindex] = (*it);
    B[lindex].insert(-1);
    ++lindex;
    ++it;
  }
  --lindex;
  for (int i = 1; i <= n; ++i) {
    pair<int, int> temp = V[i - 1].second;
    if (V[i - 1].first == 'a') {
      int qe = M[temp.first];
      B[qe].insert(temp.second);
      update(qe, temp.second, 1, lindex + 1, 1, 1);
    }
    if (V[i - 1].first == 'r') {
      int qe = M[temp.first];
      B[qe].erase(temp.second);
      set<int>::iterator it = B[qe].end();
      --it;
      update(qe, (*it), 1, lindex + 1, 1, 0);
    }
    if (V[i - 1].first == 'f') {
      int qe = M[temp.first] + 1;
      int lo = qe;
      int hi = lindex + 1;
      pair<int, int> temp2 = query(lo, hi, 1, lindex + 1, temp.second, 1);
      if (temp2.first == -1) {
        putchar('-');
        putchar('1');
        putchar('\n');
        continue;
      }
      int x = iM[temp2.second];
      int y = *(B[temp2.second].lower_bound(temp.second + 1));
      printf("%d %d\n", x, y);
    }
  }
  return 0;
}
