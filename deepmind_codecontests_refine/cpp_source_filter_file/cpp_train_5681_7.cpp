#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  for (int i = 100; i > 0; --i) {
    set<pair<int, int> > diffs;
    int sum = 0;
    bool can = true;
    diffs.insert(pair<int, int>(0, -1));
    for (int j = 0; j < n; ++j) {
      if (v[j] - i < 0)
        can = false;
      else
        diffs.insert(pair<int, int>(v[j] - i, j));
      sum += v[j] - i;
    }
    auto end = --diffs.end();
    if (can and end->first <= sum / 2) {
      cout << i << endl;
      vector<vector<int> > changes;
      while ((--diffs.end())->first != 0) {
        pair<int, int> cop;
        auto it = --diffs.end();
        int t = it->first;
        auto it2 = it;
        --it2;
        sum -= 2 * t;
        int j = 0, last = changes.size();
        while (j < t) {
          cop = *it2;
          int add = min(it2->first, t - j);
          for (int k = 0; k < add; ++k) {
            changes.push_back({it->second, it2->second});
          }
          j += add;
          --it2;
          diffs.erase(cop);
          diffs.insert(pair<int, int>(cop.first - add, cop.second));
        }
        cop = *it;
        diffs.erase(it);
        diffs.insert(pair<int, int>(0, cop.second));
        j = 0;
        while ((--diffs.end())->first > sum / 2) {
          changes[last + j].push_back((--diffs.end())->second);
          ++j;
          --sum;
          cop = *(--diffs.end());
          diffs.erase(cop);
          diffs.insert(pair<int, int>(cop.first - 1, cop.second));
        }
      }
      cout << changes.size() << endl;
      for (int k = 0; k < changes.size(); ++k) {
        vector<bool> is(n, false);
        for (int j = 0; j < changes[k].size(); ++j) is[changes[k][j]] = true;
        for (int j = 0; j < n; ++j) {
          if (is[j])
            cout << '1';
          else
            cout << '0';
        }
        cout << '/n';
      }
      return 0;
    }
  }
  cout << 0 << endl;
  sort(v.begin(), v.end());
  cout << v.back() * (n - 1) << endl;
  while (v.back() != 0) {
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j == i or j == i + 1)
          cout << '1';
        else
          cout << '0';
      }
      cout << endl;
    }
    --v[v.size() - 1];
  }
}
