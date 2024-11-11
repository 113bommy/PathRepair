#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000003;
int m;
int n;
int x[200001];
int y[200002];
int p[200002];
int l;
int s[200002];
vector<int> v[200002];
bool cmp(int i, int j) { return x[i] > x[j] || (x[i] == x[j] && y[i] > y[j]); }
bool cross(int a, int b, int c) {
  return (long long)(x[a] - x[c]) * (y[a] - y[b]) * x[b] * y[c] >
         (long long)(y[a] - y[c]) * (x[a] - x[b]) * x[c] * y[b];
}
int main(int argc, char *argv[]) {
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%d %d", x + i, y + i);
  for (int i = 0; i < n; ++i) p[i] = i;
  sort(p, p + n, cmp);
  m = 1;
  s[0] = p[0];
  for (int i = 1; i < n; ++i) {
    int j = p[i];
    if (x[s[m - 1]] == x[j] && y[s[m - 1]] == y[j]) {
      v[s[m - 1]].push_back(j);
      continue;
    }
    if (y[j] <= y[s[m - 1]]) continue;
    while (m > 1 && cross(s[m - 2], s[m - 1], j)) --m;
    s[m++] = j;
  }
  for (int i = 0; i < m; ++i) {
    for (int j : v[p[i]]) s[m++] = j;
  }
  sort(s, s + m);
  for (int i = 0; i < m; ++i) printf("%d ", s[i] + 1);
  cout << endl;
}
