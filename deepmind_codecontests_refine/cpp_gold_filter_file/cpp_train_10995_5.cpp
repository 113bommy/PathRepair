#include <bits/stdc++.h>
using namespace std;
struct Result {
  int d1;
  int d2;
  int d3;
  int v12;
  int v23;
  int v3n1;
  Result() {
    d1 = 0;
    d2 = 0;
    d3 = 0;
    v12 = INT_MIN;
    v23 = INT_MIN;
    v3n1 = INT_MIN;
  }
};
bool operator<(const Result& l, const Result& r) {
  return l.v12 < r.v12 || (l.v12 == r.v12 && l.v23 < r.v23) ||
         (l.v12 == r.v12 && l.v23 == r.v23 && l.v3n1 < r.v3n1);
}
const int MAX_D = 15;
const int MAX_N = 3000 + 10;
class SparseTable {
 public:
  SparseTable(vector<pair<int, int> >& vec) {
    N = vec.size();
    table.assign(N, vector<pair<int, int> >(MAX_D));
    depth.assign(MAX_N, -1);
    init(vec);
  }
  void init(vector<pair<int, int> >& vec) {
    depth[0] = -1;
    for (int i = 1; i < MAX_N; ++i) {
      depth[i] = depth[i - 1];
      if ((i & (i - 1)) == 0) {
        ++depth[i];
      }
    }
    for (int i = 0; i < N; ++i) {
      table[i][0] = vec[i];
    }
    for (int d = 1; d <= depth[N] + 1; ++d) {
      for (int i = 0; i < N; ++i) {
        int left = i;
        int right = min(N - 1, left + (1 << (d - 1)));
        table[i][d] = max(table[left][d - 1], table[right][d - 1]);
      }
    }
  }
  pair<int, int> getMax(int left, int right) {
    int len = right - left + 1;
    int d = depth[len];
    return max(table[left][d], table[left + len - (1 << d)][d]);
  }

 private:
  vector<vector<pair<int, int> > > table;
  int N = 0;
  vector<int> depth;
};
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int> > b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = {a[i], i};
  }
  sort(b.begin(), b.end());
  vector<pair<int, int> > c;
  c.push_back({b[0].first, 0});
  for (int i = 1; i < n; ++i) {
    c.push_back({b[i].first - b[i - 1].first, i});
  }
  SparseTable ST(c);
  Result ret;
  for (int d1 = n - 1; d1 >= 0; --d1) {
    for (int d2 = d1 - 1; d2 >= 0; --d2) {
      int cnt1 = n - 1 - d1 + 1;
      int cnt2 = d1 - 1 - d2 + 1;
      if (cnt1 > 2 * cnt2 || cnt2 > 2 * cnt1) {
        continue;
      }
      int max_cnt3 = min({d2, 2 * cnt1, 2 * cnt2});
      int min_cnt3 = max({1, (cnt1 + 1) / 2, (cnt2 + 1) / 2});
      if (max_cnt3 < min_cnt3) {
        continue;
      }
      int max_d3 = d2 - min_cnt3;
      int min_d3 = d2 - max_cnt3;
      auto max_val = ST.getMax(min_d3, max_d3);
      int d3 = max_val.second;
      Result temp;
      temp.d1 = d1;
      temp.d2 = d2;
      temp.d3 = d3;
      temp.v12 = b[d1].first - b[d1 - 1].first;
      temp.v23 = b[d2].first - b[d2 - 1].first;
      temp.v3n1 = max_val.first;
      if (ret < temp) {
        ret = temp;
      }
    }
  }
  vector<int> vec(n, 0);
  for (int i = 0; i < ret.d3; ++i) {
    vec[b[i].second] = -1;
  }
  for (int i = ret.d3; i < ret.d2; ++i) {
    vec[b[i].second] = 3;
  }
  for (int i = ret.d2; i < ret.d1; ++i) {
    vec[b[i].second] = 2;
  }
  for (int i = ret.d1; i < n; ++i) {
    vec[b[i].second] = 1;
  }
  for (auto item : vec) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}
