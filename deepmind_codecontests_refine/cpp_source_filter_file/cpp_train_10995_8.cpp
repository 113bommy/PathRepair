#include <bits/stdc++.h>
using namespace std;
const int max_depth = 15;
const int max_nodes = 3000 + 50;
class SparseTable {
 public:
  SparseTable(vector<pair<int, int> >& vals) {
    N = vals.size();
    table.assign(N, vector<pair<int, int> >(max_depth));
    calc();
    build(vals);
  }
  void build(vector<pair<int, int> >& vals) {
    for (int i = 0; i < N; ++i) {
      table[i][0] = vals[i];
    }
    for (int d = 1; d < max_depth; ++d) {
      for (int i = 0; i < N; ++i) {
        int second = min(N - 1, i + (1 << (d - 1)));
        table[i][d] = max(table[i][d - 1], table[second][d - 1]);
      }
    }
  }
  pair<int, int> getMaxVal(int left, int right) {
    int len = right - left + 1;
    int d = depths[len];
    return max(table[left][d], table[left + (1 << d)][d]);
  }
  void calc() {
    depths.assign(max_nodes, -1);
    for (int i = 1; i < max_nodes; ++i) {
      depths[i] = depths[i - 1];
      if ((i & (i - 1)) == 0) {
        ++depths[i];
      }
    }
  }

 private:
  int N;
  vector<vector<pair<int, int> > > table;
  vector<int> depths;
};
struct DP {
  int point1_val;
  int point2_val;
  int point3_val;
  int point1;
  int point2;
  int point3;
};
bool operator<(const DP& l, const DP& r) {
  return l.point1_val < r.point1_val ||
         (l.point1_val == r.point1_val && l.point2_val < r.point2_val) ||
         (l.point1_val == r.point1_val && l.point2_val == r.point2_val &&
          l.point3_val < r.point3_val);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> scores(n, 0);
  vector<pair<int, int> > vals;
  for (int i = 0; i < n; ++i) {
    cin >> scores[i];
    vals.push_back({scores[i], i});
  }
  sort(vals.begin(), vals.end());
  vector<pair<int, int> > diffs;
  diffs.push_back({vals[0].first, 0});
  for (int i = 1; i < vals.size(); ++i) {
    diffs.push_back({vals[i].first - vals[i - 1].first, i});
  }
  SparseTable sparseTable(diffs);
  DP ret;
  ret.point1_val = -1;
  ret.point2_val = -1;
  ret.point3_val = -1;
  for (int degree_1_start = n - 1; degree_1_start >= 0; --degree_1_start) {
    for (int degree_2_start = degree_1_start - 1; degree_2_start >= 0;
         --degree_2_start) {
      int degree_1_len = n - 1 - degree_1_start + 1;
      int degree_2_len = degree_1_start - 1 - degree_2_start + 1;
      if (degree_1_len > 2 * degree_2_len || degree_2_len > 2 * degree_1_len) {
        continue;
      }
      int max_degree_3_len =
          min({2 * degree_1_len, 2 * degree_2_len, degree_2_start});
      int min_degree_3_len =
          max({1, (1 + degree_1_len) / 2, (1 + degree_2_len) / 2});
      if (max_degree_3_len < min_degree_3_len) {
        continue;
      }
      int degree_3_start_min = degree_2_start - max_degree_3_len;
      int degree_3_start_max = degree_2_start - min_degree_3_len;
      pair<int, int> maxValForPoint3 =
          sparseTable.getMaxVal(degree_3_start_min, degree_3_start_max);
      DP temp;
      temp.point1_val =
          vals[degree_1_start].first - vals[degree_1_start - 1].first;
      temp.point2_val =
          vals[degree_2_start].first - vals[degree_2_start - 1].first;
      temp.point3_val = maxValForPoint3.first;
      temp.point1 = degree_1_start;
      temp.point2 = degree_2_start;
      temp.point3 = maxValForPoint3.second;
      if (ret < temp) {
        ret = temp;
      }
    }
  }
  vector<int> ret_vec(n);
  for (int i = 0; i < ret.point3; ++i) {
    ret_vec[vals[i].second] = -1;
  }
  for (int i = ret.point3; i < ret.point2; ++i) {
    ret_vec[vals[i].second] = 3;
  }
  for (int i = ret.point2; i < ret.point1; ++i) {
    ret_vec[vals[i].second] = 2;
  }
  for (int i = ret.point1; i < n; ++i) {
    ret_vec[vals[i].second] = 1;
  }
  for (auto item : ret_vec) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}
