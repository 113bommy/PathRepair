#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1000000000LL;
int arr[100000 + 5], n;
vector<int> numbers;
vector<int> positions[100000 + 5];
int rev[100000 + 5], final_answer[100000 + 5];
inline int __map(int value) {
  return lower_bound(numbers.begin(), numbers.end(), value) - numbers.begin() +
         1;
}
struct node {
  long long int sum, mxP, mxS, mcs;
  node *l, *r;
  node(long long int x = -INF) {
    l = r = 0;
    sum = x;
    mxP = mxS = mcs = (x < 0) ? 0 : x;
  }
} * ROOT[100000 + 11];
void init(node *current, int st, int ed) {
  if (st == ed) return;
  int mid = (st + ed) / 2;
  current->l = new node;
  current->r = new node;
  init(current->l, st, mid);
  init(current->r, mid + 1, ed);
}
void update(node *current, node *previous, int st, int ed, int pos, int val) {
  if (st == ed) {
    *current = node(1);
    return;
  }
  int mid = (st + ed) / 2;
  if (pos <= mid) {
    current->l = new node;
    current->r = previous->r;
    update(current->l, previous->l, st, mid, pos, val);
  } else {
    current->r = new node;
    current->l = previous->l;
    update(current->r, previous->r, mid + 1, ed, pos, val);
  }
  current->mcs = max(current->l->mcs, current->r->mcs);
  current->mcs = max(current->mcs, current->l->mxS + current->r->mxP);
  current->mxS = max(current->r->mxS, current->r->sum + current->l->mxS);
  current->mxP = max(current->l->mxP, current->l->sum + current->r->mxP);
  current->sum = current->l->sum + current->r->sum;
  return;
}
node query(node *current, int st, int ed, int i, int j) {
  if (st == i && ed == j) return *current;
  int mid = (st + ed) / 2;
  if (j <= mid) return query(current->l, st, mid, i, j);
  if (i > mid)
    return query(current->r, mid + 1, ed, i, j);
  else {
    node u = query(current->l, st, mid, i, mid);
    node v = query(current->r, mid + 1, ed, mid + 1, j);
    node ret;
    ret.mcs = max(u.mcs, v.mcs);
    ret.mcs = max(ret.mcs, u.mxS + v.mxP);
    ret.mxS = max(v.mxS, v.sum + u.mxS);
    ret.mxP = max(u.mxP, u.sum + v.mxP);
    ret.sum = u.sum + v.sum;
    return ret;
  }
}
void init() {
  int i, j;
  for (i = 1; i <= n; i++) {
    positions[__map(arr[i])].push_back(i);
    rev[__map(arr[i])] = arr[i];
  }
  ROOT[0] = new node;
  init(ROOT[0], 1, n);
  int current = 1;
  for (int value = numbers.size(); value >= 1; value--) {
    for (i = 0; i < positions[value].size(); i++) {
      ROOT[current] = new node;
      update(ROOT[current], ROOT[current - 1], 1, n, positions[value][i], 1);
      final_answer[value] = current;
      current++;
    }
  }
}
int Qry(int l, int r, int mid) {
  return query(ROOT[final_answer[mid]], 1, n, l, r).mcs;
}
int brute(int l, int r, int w) {
  int i, j, k, mn, ret = numeric_limits<int>::min();
  for (i = l; i <= r; i++) {
    if (i + w - 1 > r) break;
    mn = numeric_limits<int>::max();
    for (k = i; k <= i + w - 1; k++) mn = min(mn, arr[k]);
    ret = max(ret, mn);
  }
  return ret;
}
int main() {
  int i, j, k, q;
  int l, r, w, lo, hi, mid;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", arr + i);
    numbers.push_back(arr[i]);
  }
  sort(numbers.begin(), numbers.end());
  numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
  init();
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d %d", &l, &r, &w);
    lo = 1;
    hi = numbers.size();
    while (lo != hi) {
      mid = lo + (hi - lo + 1) / 2;
      int maxW = Qry(l, r, mid);
      if (maxW >= w)
        lo = mid;
      else
        hi = mid - 1;
    }
    printf("%d\n", rev[lo]);
  }
  return 0;
}
