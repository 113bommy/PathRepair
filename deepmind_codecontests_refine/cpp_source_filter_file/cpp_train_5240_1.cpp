#include <bits/stdc++.h>
using namespace std;
int tree[27][2000000 + 5];
vector<int> data[244];
int del[2000000 + 6];
int read(int t, int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += tree[t][idx];
    idx -= (idx & -idx);
  }
  return sum;
}
void update(int t, int idx, int val) {
  while (idx <= 2000000) {
    tree[t][idx] += val;
    idx += (idx & -idx);
  }
}
int bin(int t, int tar) {
  int i = 1, j = 2000000;
  while (i < j) {
    int x = (i + j) / 2;
    if (tar <= read(t, x))
      j = x;
    else
      i = x + 1;
  }
  return i;
}
void init() {
  for (int i = 1; i <= 26; ++i) {
    int siz = data[i].size();
    for (int j = 1; j <= siz + 1; ++j) update(i, j, 1);
  }
}
int main() {
  int k, ll, n, p;
  char c;
  string ss;
  cin >> k >> ss;
  ll = ss.length();
  ss = " " + ss;
  for (int i = 1; i <= k; ++i) {
    for (int p = 1; p <= ll; ++p) {
      data[ss[p] - 'a' + 1].push_back(p + (i - 1) * k);
    }
  }
  init();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p >> c;
    int num = bin(c - 'a' + 1, p);
    del[data[c - 'a' + 1][num - 1]] = 1;
    update(c - 'a' + 1, num, -1);
  }
  for (int i = 1; i <= k; ++i) {
    for (int p = 1; p <= ll; ++p) {
      if (del[p + (i - 1) * ll] == 0) cout << ss[p];
    }
  }
}
