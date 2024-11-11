#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int c[N];
int a[N];
void add(int x, int val) {
  for (int i = x; i <= n; i += i & -i) {
    c[i] += val;
  }
}
int sum(int x) {
  int res = 0;
  for (int i = x; i; i -= i & -i) {
    res += c[i];
  }
  return res;
}
vector<int> pos[N];
vector<int> seq;
int dis(int from, int to) {
  if (to >= from)
    return to - from;
  else {
    return n - from + to;
  }
}
int get(int from, int to) {
  int res;
  if (to >= from) {
    res = sum(to) - sum(from);
  } else {
    res = sum(n) - sum(from) + sum(to);
  }
  add(to, -1);
  return res;
}
int main() {
  while (cin >> n) {
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      add(i + 1, 1);
      pos[a[i]].push_back(i);
    }
    int pre = 0;
    for (int i = 1; i < N; i++) {
      if (pos[i].size()) {
        int t = 0;
        for (int j = 0; j < pos[i].size(); j++) {
          if (dis(pre, pos[i][j]) <= dis(pre, pos[i][t])) {
            t = j;
          }
        }
        for (int j = t; j < pos[i].size(); j++) {
          seq.push_back(pos[i][j]);
        }
        for (int j = 0; j < t; j++) {
          seq.push_back(pos[i][j]);
        }
        pre = seq.back();
      }
    }
    pre = 0;
    long long res = 0;
    for (int i = 0; i < seq.size(); i++) {
      res += get(pre + 1, seq[i] + 1);
      pre = seq[i];
    }
    cout << res + 1 << endl;
  }
  return 0;
}
