#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const unsigned long long INF64 = 3e18;
const long double EPS = 1e-12;
const long double PI = 3.1415926535897932384620;
const unsigned long long MD = 925262732;
const unsigned long long T = 634521;
const int N = 300101;
const int M = 1010;
const int MAGIC = 4000;
int n, m, a[M][M], d[M][M];
vector<int> b;
bool check(int first) {
  for (int i = 0; i < int(m); i++)
    for (int j = 0; j < int(m); j++) d[i][j] = 0;
  for (int i = 0; i < int(n); i++) {
    b.clear();
    for (int j = 0; j < int(m); j++)
      if (a[i][j] >= first) b.push_back(j);
    for (int first = 0; first < int(int((b).size())); first++)
      for (int second = first + 1; second < int((b).size()); second++) {
        d[b[first]][b[second]]++;
        if (d[b[first]][b[second]] > 1) return 1;
      }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(m); j++) cin >> a[i][j];
  int l = 0, r = 1000000001;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (check(m))
      l = m;
    else
      r = m;
  }
  cout << l;
  return 0;
}
