#include <bits/stdc++.h>
const int N = 1 << 18;
const int R = 1000;
using namespace std;
vector<pair<int, int> > alueet[100003];
long long st[2 * N];
long long sisu[2 * N];
long long addValue(int k, int l, int r, int x, int y) {
  if (l > y || r < x) return st[k];
  int len = min(y, r) - max(l, x) + 1;
  if (l >= x && r <= y) {
    sisu[k]++;
    st[k] += len;
    return st[k];
  }
  int mid = (l + r) >> 1;
  long long q = addValue(k * 2, l, mid, x, y);
  long long w = addValue(k * 2 + 1, mid + 1, r, x, y);
  return st[k] = q + w + sisu[k] * (r - l + 1);
}
long long getSum(int k, int l, int r, int x, int y) {
  if (l > y || r < x) return 0;
  int len = min(y, r) - max(l, x) + 1;
  if (l >= x && r <= y) {
    return st[k];
  }
  int mid = (l + r) >> 1;
  long long q = getSum(k * 2, l, mid, x, y);
  long long w = getSum(k * 2 + 1, mid + 1, r, x, y);
  return q + w + sisu[k] * len;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> leaders;
  vector<pair<int, int> > v(4 * m);
  for (int i = 0; i < 4 * m; i += 4) {
    char q;
    cin >> q;
    v[i].first = q;
    cin >> v[i].second;
    --v[i].second;
    if (alueet[v[i].second].size() == 0) {
      if (q == '+')
        alueet[v[i].second].push_back({i, 150000});
      else
        alueet[v[i].second].push_back({-10, i});
    } else if (q == '-') {
      alueet[v[i].second].back().second = i;
    } else {
      alueet[v[i].second].push_back({i, 150000});
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < alueet[i].size(); ++j) {
      addValue(1, 0, N - 1, alueet[i][j].first + R, alueet[i][j].second + R);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (alueet[i].size() == 0) {
      leaders.push_back(i);
      continue;
    }
    if (alueet[i].size()) {
      if (alueet[i][0].first > -10) {
        if (getSum(1, 0, N - 1, -10 + R, alueet[i][0].first + R - 1) > 0) {
          goto ohi;
        }
      }
      if (alueet[i].back().second < 150000) {
        if (getSum(1, 0, N - 1, alueet[i].back().second + R + 1, N - 1) > 0) {
          goto ohi;
        }
      }
    }
    for (int j = 1; j < alueet[i].size(); ++j) {
      if (getSum(1, 0, N - 1, alueet[i][j - 1].second + R + 1,
                 alueet[i][j].first + R - 1) > 0) {
        goto ohi;
      }
    }
    leaders.push_back(i);
  ohi:;
  }
  sort(leaders.begin(), leaders.end());
  cout << leaders.size() << '\n';
  for (auto x : leaders) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
}
