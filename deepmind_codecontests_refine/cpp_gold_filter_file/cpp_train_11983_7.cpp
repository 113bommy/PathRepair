#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> ans;
  vector<int> steps = {0};
  for (int j = 0; j < 6; ++j) {
    for (int i = 1; j + i <= 6; ++i) {
      steps.push_back((1 << j) | (1 << (j + i)) | (1 << (j + 2 * i)));
    }
  }
  vector<pair<int, int>> dpans(1 << 6);
  for (int mask = 1; mask < (1 << 6); ++mask) {
    for (int i = 0; i < steps.size(); ++i) {
      for (int j = i + 1; j < steps.size(); ++j) {
        if (((steps[i] ^ steps[j]) & ((1 << 6) - 1)) == mask) {
          dpans[mask] = {steps[i], steps[j]};
        }
      }
    }
    assert(dpans[mask] != make_pair(0, 0));
  }
  while (n >= 14) {
    int cur = 0;
    for (int i = 0; i < 6; ++i) {
      if (a[n - 1 - i]) {
        cur |= (1 << i);
      }
    }
    auto x = dpans[cur];
    for (int j = 0; j < 2; ++j) {
      for (int i = 0; x.first != 0; ++i) {
        if (x.first & (1 << i)) {
          x.first ^= (1 << i);
          ans.push_back(n - 1 - i);
          a[n - 1 - i] ^= 1;
        }
      }
      swap(x.first, x.second);
    }
    for (int i = 0; i < 6; ++i) {
      assert(a.back() == 0);
      a.pop_back();
      --n;
    }
  }
  steps.clear();
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (i + 2 * j < n) {
        steps.push_back((1 << i) | (1 << (i + j)) | (1 << (i + 2 * j)));
      }
    }
  }
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      cur |= (1 << i);
    }
  }
  vector<vector<int>> aans(1 << n);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i : steps) {
      if (aans[i ^ x].empty() && ((i ^ x) != 0)) {
        aans[i ^ x] = aans[x];
        aans[i ^ x].push_back(i);
        q.push(i ^ x);
      }
    }
  }
  if (cur != 0 && aans[cur].empty()) {
    cout << "No" << endl;
  } else {
    for (int x : aans[cur]) {
      for (int i = 0; i < n; ++i) {
        if (x & (1 << i)) {
          ans.push_back(i);
        }
      }
    }
    cout << "Yes" << endl;
    assert(ans.size() % 3 == 0);
    cout << ans.size() / 3 << endl;
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] + 1 << ' ';
      if (i % 3 == 2) {
        cout << '\n';
      }
    }
  }
  return 0;
}
