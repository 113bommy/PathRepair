#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n;
  int q;
  vector<int> a;
  vector<pair<int, int> > sw;
  vector<int> diff;
  vector<vector<long long int> > res;
  for (int run = 0; run < t; run++) {
    cin >> n >> q;
    a.clear();
    for (int i = 0; i < n; i++) {
      a.push_back(0);
      cin >> a[i];
    }
    sw.clear();
    for (int i = 0; i < q; i++) {
      sw.push_back(pair<int, int>());
      cin >> sw[i].first >> sw[i].second;
      sw[i].first -= 1;
      sw[i].second -= 1;
    }
    diff.clear();
    res.push_back(vector<long long int>());
    res[run].push_back(0);
    for (int i = 0; i < n - 1; i++) {
      diff.push_back(a[i] - a[i + 1]);
      if (diff[i] > 0) {
        res[run][0] += diff[i];
      }
    }
    diff.push_back(a.back());
    res[run][0] += a.back();
    for (int i = 0; i < q; i++) {
      if (sw[i].first == sw[i].second) {
        res[run].push_back(res[run][i]);
        continue;
      }
      res[run].push_back(res[run][i]);
      if (sw[i].second - sw[i].first == 1) {
        if (sw[i].first == 0 && sw[i].second == n - 1) {
          if (diff[0] > 0) {
            res[run].back() -= diff[0];
          }
          diff[0] = -diff[0];
          if (diff[0] > 0) {
            res[run].back() += diff[0];
          }
          res[run].back() -= diff[1];
          diff[1] = a[0];
          res[run].back() += diff[1];
          int temp = a[0];
          a[0] = a[1];
          a[1] = a[0];
        } else if (sw[i].first == 0) {
          if (diff[0] < 0) {
            res[run].back() += -diff[0];
          } else if (diff[0] > 0) {
            res[run].back() -= diff[0];
          }
          diff[0] = -diff[0];
          if (diff[1] > 0) {
            res[run].back() -= diff[1];
          }
          diff[1] = a[0] - a[2];
          if (diff[1] > 0) {
            res[run].back() += diff[1];
          }
          int temp = a[0];
          a[0] = a[1];
          a[1] = temp;
        } else if (sw[i].second == n - 1) {
          res[run].back() -= diff.back();
          res[run].back() += a[n - 2];
          diff.back() = a[n - 2];
          if (diff[diff.size() - 2] > 0) {
            res[run].back() -= diff[diff.size() - 2];
          }
          diff[diff.size() - 2] = -diff[diff.size() - 2];
          if (diff[diff.size() - 2] > 0) {
            res[run].back() += diff[diff.size() - 2];
          }
          if (diff[diff.size() - 3] > 0) {
            res[run].back() -= diff[diff.size() - 3];
          }
          if (a[n - 3] - a.back() > 0) {
            res[run].back() += a[n - 3] - a.back();
          }
          diff[diff.size() - 3] = a[n - 3] - a.back();
          int temp = a.back();
          a.back() = a[n - 2];
          a[n - 2] = temp;
        } else {
          if (diff[sw[i].first] > 0) {
            res[run].back() -= diff[sw[i].first];
          }
          diff[sw[i].first] = -diff[sw[i].first];
          if (diff[sw[i].first] > 0) {
            res[run].back() += diff[sw[i].first];
          }
          if (diff[sw[i].first - 1] > 0) {
            res[run].back() -= diff[sw[i].first - 1];
          }
          if (diff[sw[i].first + 1] > 0) {
            res[run].back() -= diff[sw[i].first + 1];
          }
          diff[sw[i].first - 1] = a[sw[i].first - 1] - a[sw[i].first + 1];
          if (diff[sw[i].first - 1] > 0) {
            res[run].back() += diff[sw[i].first - 1];
          }
          diff[sw[i].first + 1] = a[sw[i].first] - a[sw[i].first + 2];
          if (diff[sw[i].first + 1] > 0) {
            res[run].back() += diff[sw[i].first + 1];
          }
          int temp = a[sw[i].first];
          a[sw[i].first] = a[sw[i].first + 1];
          a[sw[i].first + 1] = temp;
        }
      } else {
        if (sw[i].first == 0) {
          if (diff[0] > 0) {
            res[run].back() -= diff[0];
          }
          diff[0] = a[sw[i].second] - a[1];
          if (diff[0] > 0) {
            res[run].back() += diff[0];
          }
        } else {
          if (diff[sw[i].first] > 0) {
            res[run].back() -= diff[sw[i].first];
          }
          diff[sw[i].first] = a[sw[i].second] - a[sw[i].first + 1];
          if (diff[sw[i].first] > 0) {
            res[run].back() += diff[sw[i].first];
          }
          if (diff[sw[i].first - 1] > 0) {
            res[run].back() -= diff[sw[i].first - 1];
          }
          diff[sw[i].first - 1] = a[sw[i].first - 1] - a[sw[i].second];
          if (diff[sw[i].first - 1] > 0) {
            res[run].back() += diff[sw[i].first - 1];
          }
        }
        if (sw[i].second == n - 1) {
          res[run].back() -= diff.back();
          diff.back() = a[sw[i].first];
          res[run].back() += diff.back();
          if (diff[diff.size() - 2] > 0) {
            res[run].back() -= diff[diff.size() - 2];
          }
          diff[diff.size() - 2] = a[n - 2] - a[sw[i].first];
          if (diff[n - 2] > 0) {
            res[run].back() += diff[n - 2];
          }
        } else {
          if (diff[sw[i].second] > 0) {
            res[run].back() -= diff[sw[i].second];
          }
          diff[sw[i].second] = a[sw[i].first] - a[sw[i].second + 1];
          if (diff[sw[i].second] > 0) {
            res[run].back() += diff[sw[i].second];
          }
          if (diff[sw[i].second - 1] > 0) {
            res[run].back() -= diff[sw[i].second - 1];
          }
          diff[sw[i].second - 1] = a[sw[i].second - 1] - a[sw[i].first];
          if (diff[sw[i].second - 1] > 0) {
            res[run].back() += diff[sw[i].second - 1];
          }
        }
        int temp = a[sw[i].first];
        a[sw[i].first] = a[sw[i].second];
        a[sw[i].second] = temp;
      }
    }
  }
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << endl;
    }
  }
  cin.sync();
  cin.get();
  return 0;
}
