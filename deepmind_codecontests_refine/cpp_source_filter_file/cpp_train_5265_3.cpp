#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000 + 10, mod = 1000000007;
int n, ith1[30][MAX_N], ith0[30][MAX_N];
void make1(int x) {
  int t = (1 << x);
  vector<int> v;
  for (int(i) = (1); (i) <= (n); (i)++) {
    if (i & t) v.push_back(i);
  }
  if (!v.empty()) {
    cout << v.size() << endl;
    for (int(i) = (0); (i) <= (v.size() - 1); (i)++) {
      cout << v[i] << " ";
    }
    cout << endl;
    int ret;
    for (int i = 1; i <= n; i++) {
      cin >> ret;
      ith1[x][i] = ret;
    }
  } else {
    for (int i = 1; i <= n; i++) {
      ith1[x][i] = 1000000001;
    }
  }
}
void make0(int x) {
  int t = (1 << x);
  vector<int> v;
  for (int(i) = (1); (i) <= (n); (i)++) {
    if ((i & t) == 0) v.push_back(i);
  }
  if (!v.empty()) {
    cout << v.size() << endl;
    for (int(i) = (0); (i) <= (v.size() - 1); (i)++) {
      cout << v[i] << " ";
    }
    cout << endl;
    int ret;
    for (int i = 1; i <= n; i++) {
      cin >> ret;
      ith0[x][i] = ret;
    }
  } else {
    for (int i = 1; i <= n; i++) {
      ith0[x][i] = 1000000001;
    }
  }
}
int get(int x) {
  int t = 1, pw = 0;
  int mn = 1000000001;
  while (t <= n) {
    if (t & n) {
      mn = min(ith0[pw][x], mn);
    } else {
      mn = min(ith1[pw][x], mn);
    }
    t *= 2;
    pw++;
  }
  return mn;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int(i) = (0); (i) <= (9); (i)++) {
    make0(i);
    make1(i);
  }
  cout << -1 << endl;
  for (int i = 1; i <= n; i++) {
    cout << get(i) << " ";
  }
  cout << endl;
  return 0;
}
