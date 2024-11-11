#include <bits/stdc++.h>
using namespace std;
vector<int> seq;
int d[505][505], d2[505];
int go(int s, int e) {
  if (e - s == 1) return d[s][e] = seq[s];
  int& res = d[s][e];
  if (res) return res;
  res = -1;
  for (int i = s + 1; i < e; ++i) {
    int res1 = go(s, i);
    int res2 = go(i, e);
    if (res1 && res1 == res2) return res = res1 + 1;
  }
  return res;
}
void solve() {
  memset(d2, 0x3f, sizeof(d2));
  int n;
  scanf("%d", &n);
  seq.resize(n);
  for (int i = 0; i < n; ++i) scanf("%d", &seq[i]);
  d2[0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (go(i, j)) d2[j] = min(d2[j], d2[i] + 1);
  printf("%d", d2[n]);
}
int main() { solve(); }
