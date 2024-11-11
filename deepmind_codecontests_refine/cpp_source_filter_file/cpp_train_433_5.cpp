#include <bits/stdc++.h>
using namespace std;
template <class T>
int chkmax(T& a, T b) {
  if (b > a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
int chkmin(T& a, T b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class iterator>
void output(iterator begin, iterator end, ostream& out = cerr) {
  while (begin != end) {
    out << (*begin) << " ";
    begin++;
  }
  out << endl;
}
template <class T>
void output(T x, ostream& out = cerr) {
  output(x.begin(), x.end(), out);
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int INF = 1e9;
const int N = 26;
const int A = 5e4 + 10;
vector<int> value;
int p[N][A * N];
signed main() {
  fast_io();
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    int x;
    cin >> x;
    value.push_back(x);
  }
  sort(value.begin(), value.end());
  int sum = 0;
  for (int i = 3; i < 2 * n; ++i) {
    sum += value[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < A * N; ++j) {
      p[i][j] = -1;
    }
  }
  p[0][0] = -2;
  for (int i = 3; i < value.size(); ++i) {
    int cur = value[i];
    for (int j = n - 1; j > 0; --j) {
      for (int x = cur; x < A * N; ++x) {
        if (p[j - 1][x - cur] != -1 && p[j][x] == -1) {
          p[j][x] = i;
        }
      }
    }
  }
  int best = INF;
  for (int i = 0; i < N * A; ++i) {
    if (abs(i - (sum - i)) < abs(best - (sum - best)) && p[n - 1][i] != -1) {
      best = i;
    }
  }
  vector<int> type(2 * n);
  type[1] = 1;
  for (int i = n - 1; i > 0; --i) {
    type[p[i][best]] = 1;
    best -= value[p[i][best]];
  }
  vector<vector<int> > ans(2);
  for (int i = 0; i < 2 * n; ++i) {
    ans[type[i]].push_back(value[i]);
  }
  sort(ans[0].begin(), ans[0].end());
  sort(ans[1].rbegin(), ans[1].rend());
  for (auto v : ans) {
    for (auto x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
}
