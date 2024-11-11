#include <bits/stdc++.h>
using namespace std;
int n, t, A[200005], SIZE = 500;
long long ans, ansid[200005];
int K[1000005];
class query {
 public:
  int l, r, id, block;
  query(int _l, int _r, int _id, int _block) {
    l = _l;
    r = _r;
    id = _id;
    block = _block;
  }
  query() { l = r = id = block = 123456789; }
};
query queries[200005];
bool comp(const query &a, const query &b) {
  if (a.block != b.block) return a.block < b.block;
  return a.r < b.r;
}
void add(int ind) {
  K[A[ind]]++;
  long long t = K[A[ind]];
  ans += (t * 2 - 1) * A[ind];
}
void remove(int ind) {
  K[A[ind]]--;
  long long t = K[A[ind]];
  ans += (-t * 2 - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> t;
  for (int i = 0; i < n; i++) cin >> A[i];
  int curL = 0, curR = 0;
  add(0);
  for (int i = 0; i < t; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    queries[i] = query(l, r, i, l / SIZE);
  }
  sort(queries, queries + t, comp);
  for (int i = 0; i < t; i++) {
    int l, r;
    l = queries[i].l;
    r = queries[i].r;
    while (curL < l) {
      remove(curL);
      curL++;
    }
    while (curL > l) {
      add(curL - 1);
      curL--;
    }
    while (curR < r) {
      add(curR + 1);
      curR++;
    }
    while (curR > r) {
      remove(curR);
      curR--;
    }
    ansid[queries[i].id] = ans;
  }
  for (int i = 0; i < t; i++) cout << ansid[i] << "\n";
}
