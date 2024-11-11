#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const long long BINF = 1e18 + 10;
const int N = 1010;
bool used[N][N];
void go1(pair<int, int> from, pair<int, int> to, vector<pair<int, int> > &ans) {
  while (from.first != to.first) {
    used[from.first][from.second] = true;
    ans.push_back(from);
    if (from.first > to.first) {
      from.first--;
    } else {
      from.first++;
    }
  }
  while (from.second != to.second) {
    used[from.first][from.second] = true;
    ans.push_back(from);
    if (from.second > to.second) {
      from.second--;
    } else {
      from.second++;
    }
  }
  used[to.first][to.second] = true;
}
void go2(pair<int, int> from, pair<int, int> to, vector<pair<int, int> > &ans) {
  while (from.second != to.second) {
    used[from.first][from.second] = true;
    ans.push_back(from);
    if (from.second > to.second) {
      from.second--;
    } else {
      from.second++;
    }
  }
  while (from.first != to.first) {
    used[from.first][from.second] = true;
    ans.push_back(from);
    if (from.first > to.first) {
      from.first--;
    } else {
      from.first++;
    }
  }
  used[to.first][to.second] = true;
}
void source() {
  vector<pair<int, int> > arr(3);
  for (auto &it : arr) {
    cin >> it.first >> it.second;
  }
  sort((arr).begin(), (arr).end());
  vector<pair<int, int> > ans;
  if (abs(arr[0].second - arr[1].second) + abs(arr[1].second - arr[2].second) ==
      abs(arr[0].second - arr[2].second)) {
    go1(arr[0], arr[1], ans);
    go1(arr[1], arr[2], ans);
    ans.push_back(arr[2]);
  } else {
    if (arr[1].second > max(arr[0].second, arr[2].second)) {
      if (arr[0].second <= arr[2].second) {
        go1(arr[0], arr[2], ans);
      } else {
        go2(arr[0], arr[2], ans);
      }
      ans.push_back(arr[2]);
      while (!used[arr[1].first][arr[1].second]) {
        ans.push_back(arr[1]);
        arr[1].second--;
      }
    } else {
      if (arr[0].second <= arr[2].second) {
        go2(arr[0], arr[2], ans);
      } else {
        go1(arr[0], arr[2], ans);
      }
      ans.push_back(arr[2]);
      while (!used[arr[1].first][arr[1].second]) {
        ans.push_back(arr[1]);
        arr[1].second++;
      }
    }
  }
  cout << ((int)ans.size()) << '\n';
  for (auto it : ans) {
    cout << it.first << ' ' << it.second << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}
