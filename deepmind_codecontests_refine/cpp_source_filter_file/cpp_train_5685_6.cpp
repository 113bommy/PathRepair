#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, pair<pair<int, int>, pair<int, int> > > > ans;
void solve(int L, int R) {
  if (R - L + 1 == 3) {
    ans.push_back({3, {{L, L + 1}, {L + 2, 0}}});
    ans.push_back({3, {{L, L + 1}, {L + 2, 0}}});
    return;
  }
  if (R - L + 1 == 4) {
    ans.push_back({4, {{L, L + 1}, {L + 2, L + 3}}});
    ans.push_back({4, {{L, L + 1}, {L + 3, L + 2}}});
    ans.push_back({4, {{L, L + 2}, {L + 1, L + 3}}});
    return;
  }
  if (R - L + 1 == 6) {
    solve(L, L + 3);
    ans.push_back({4, {{L, L + 4}, {L + 1, L + 5}}});
    ans.push_back({4, {{L, L + 4}, {L + 1, L + 5}}});
    ans.push_back({4, {{L + 2, L + 4}, {L + 3, L + 4}}});
    ans.push_back({3, {{L + 4, L + 5}, {L + 3, 0}}});
    ans.push_back({3, {{L + 4, L + 5}, {L + 2, 0}}});
    return;
  }
  if ((R - L + 1) % 2 == 1) {
    ans.push_back({3, {{L, L + 1}, {L + 2, 0}}});
    ans.push_back({3, {{L, L + 1}, {L + 2, 0}}});
    for (int i = L + 3; i <= R; i += 2) {
      ans.push_back({4, {{L, i}, {L + 1, i + 1}}});
      ans.push_back({4, {{L, i}, {L + 1, i + 1}}});
    }
    solve(L + 2, R);
    return;
  }
  if ((R - L + 1) % 4 == 0) {
    for (int i = L + 4; i <= R; i += 2) {
      ans.push_back({4, {{L, i}, {L + 1, i + 1}}});
      ans.push_back({4, {{L, i}, {L + 1, i + 1}}});
    }
    for (int i = L + 4; i <= R; i += 2) {
      ans.push_back({4, {{L + 2, i}, {L + 3, i + 1}}});
      ans.push_back({4, {{L + 2, i}, {L + 3, i + 1}}});
    }
    solve(L, L + 3);
    solve(L + 4, R);
    return;
  }
  if ((R - L + 1) % 4 == 2) {
    for (int i = L + 4; i <= R; i += 2) {
      ans.push_back({4, {{L, i}, {L + 1, i + 1}}});
      ans.push_back({4, {{L, i}, {L + 1, i + 1}}});
    }
    for (int i = L + 4; i <= R; i += 2) {
      ans.push_back({4, {{L + 2, i}, {L + 3, i + 1}}});
      ans.push_back({4, {{L + 2, i}, {L + 3, i + 1}}});
    }
    for (int i = L + 4; i <= R; i += 2) {
      ans.push_back({4, {{L + 4, i}, {L + 5, i + 1}}});
      ans.push_back({4, {{L + 4, i}, {L + 5, i + 1}}});
    }
    solve(L, L + 5);
    solve(L + 6, R);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  solve(1, n);
  cout << ans.size() << endl;
  for (auto u : ans) {
    if (u.first == 3) {
      cout << u.first << "  " << u.second.first.first << " "
           << u.second.first.second << " " << u.second.second.first << endl;
    } else {
      cout << u.first << "  " << u.second.first.first << " "
           << u.second.first.second << " " << u.second.second.first << " "
           << u.second.second.second << endl;
    }
  }
  return 0;
}
