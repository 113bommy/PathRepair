#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-10;
vector<pair<int, int> > nums[2];
vector<int> id;
int sum[2][100010];
int main() {
  int n, v;
  int type, cap;
  while (cin >> n >> v) {
    int res = 0;
    id.clear();
    for (int i = 0; i < 2; i++) nums[i].clear();
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++) {
      cin >> type >> cap;
      nums[type - 1].push_back(pair<int, int>(cap, i + 1));
    }
    for (int i = 0; i < 2; i++)
      sort(nums[i].begin(), nums[i].end(), greater<pair<int, int> >());
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < (int)nums[i].size(); j++)
        sum[i][j + 1] = sum[i][j] + nums[i][j].first;
    for (int i = 0; i < (int)nums[1].size() + 1; i++) {
      int rest = v - i * 2;
      int c = sum[1][i];
      if (rest < 0)
        continue;
      else
        res = max(res, c + sum[0][min(rest, (int)nums[0].size())]);
    }
    for (int i = 0; i < (int)nums[1].size() + 1; i++) {
      int rest = v - i * 2;
      int c = sum[1][i];
      if (rest < 0) continue;
      if (res == sum[0][min(rest, (int)nums[0].size())] + c) {
        for (int j = 0; j < i; j++) id.push_back(nums[1][j].second);
        for (int j = 0; j < min(rest, (int)nums[0].size()); j++)
          id.push_back(nums[0][j].second);
        break;
      }
    }
    ostringstream out;
    for (int i = 0; i < (int)id.size(); i++) {
      if (i != 0) out << " ";
      out << id[i];
    }
    cout << res << endl;
    cout << out.str() << endl;
  }
  return 0;
}
