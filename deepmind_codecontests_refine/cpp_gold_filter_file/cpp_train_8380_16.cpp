#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1000 * 1000 * 1000 + 7;
constexpr long long inf = 1e15;
int x, y, xs, ys;
bool marked[500][500];
vector<int> ans;
int ans_sum;
string seq;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> x >> y >> xs >> ys;
  cin >> seq;
  marked[--xs][--ys] = true;
  ans.push_back(1);
  ans_sum = 1;
  for (char c : seq) {
    switch (c) {
      case 'L':
        --ys;
        break;
      case 'R':
        ++ys;
        break;
      case 'U':
        --xs;
        break;
      case 'D':
        ++xs;
        break;
    }
    xs = max(xs, 0);
    ys = max(ys, 0);
    xs = min(xs, x - 1);
    ys = min(ys, y - 1);
    ans.push_back(!marked[xs][ys]);
    ans_sum += !marked[xs][ys];
    marked[xs][ys] = true;
  }
  ans.back() += x * y - ans_sum;
  for (int i = 0; i < ans.size(); ++i) {
    if (i == ans.size() - 1)
      cout << ans[i] << endl;
    else
      cout << ans[i] << ' ';
  }
}
