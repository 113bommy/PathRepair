#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int maxn = 1e6 + 10;
const int MAX_VAL = 1000006;
void update(int i, int add, vector<int> &BIT) {
  while (i > 0 && i < BIT.size()) {
    BIT[i] += add;
    i = i + (i & (-i));
  }
}
int sum(int i, vector<int> &BIT) {
  int ans = 0;
  while (i > 0) {
    ans += BIT[i];
    i = i - (i & (-i));
  }
  return ans;
}
int findKthSmallest(int k, vector<int> &BIT) {
  int l = 0;
  int h = BIT.size();
  while (l < h) {
    int mid = (l + h) / 2;
    if (k <= sum(mid, BIT))
      h = mid;
    else
      l = mid + 1;
  }
  return l;
}
void insertElement(int x, vector<int> &BIT) { update(x, 1, BIT); }
void deleteElement(int x, vector<int> &BIT) { update(x, -1, BIT); }
int findRank(int x, vector<int> &BIT) { return sum(x, BIT); }
void solve() {
  long long int n, q;
  cin >> n >> q;
  vector<int> BIT(MAX_VAL);
  for (int i = 0; i < n; i++) {
    long long int e;
    cin >> e;
    insertElement(e, BIT);
  }
  vector<long long int> queries(q);
  for (int i = 0; i < q; i++) {
    cin >> queries[i];
    if (queries[i] < 0) {
      int el = findKthSmallest(abs(queries[i]), BIT);
      deleteElement(el, BIT);
    } else {
      insertElement(queries[i], BIT);
    }
  }
  for (int i = 0; i < MAX_VAL; i++) {
    if (BIT[i] != 0) {
      cout << i << "\n";
      return;
    }
  }
  cout << "0\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) solve();
  cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
