#include <bits/stdc++.h>
using namespace std;
class SparseTable {
 public:
  SparseTable(const vector<int>& values) : values{values} {
    int n = (int)values.size(), logn = (int)log2(n);
    table.resize(n, vector<int>(logn + 1));
    for (int i = 0; i < n; ++i) {
      table[i][0] = i;
    }
    for (int j = 1; j <= logn; ++j) {
      for (int i = 0; i + (1 << j) - 1 < n; ++i) {
        table[i][j] =
            values[table[i][j - 1]] > values[table[i + (1 << (j - 1))][j - 1]]
                ? table[i][j - 1]
                : table[i + (1 << (j - 1))][j - 1];
      }
    }
  }
  int query(int begin, int end) {
    int logr = (int)log2(end - begin);
    return values[table[begin][logr]] > values[table[end - (1 << logr)][logr]]
               ? table[begin][logr]
               : table[end - (1 << logr)][logr];
  }

 private:
  const vector<int>& values;
  vector<vector<int>> table;
};
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n - 1; ++i) {
    cin >> a[i];
  }
  a[n - 1] = n;
  SparseTable table(a);
  vector<int> dp(n);
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    int first = table.query(i + 1, a[i]);
    dp[i] = dp[first] + (n - i - 1) - (a[i] - first - 1);
  }
  cout << accumulate(dp.begin(), dp.end(), 0LL) << endl;
}
