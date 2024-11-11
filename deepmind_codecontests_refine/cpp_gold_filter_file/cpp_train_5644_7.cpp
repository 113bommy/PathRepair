#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 3e5 + 5;
const long long MAX2 = 11;
const long long MOD = 1000000007;
const long long MOD2 = 1000000006;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
long long n, m, x[MAX];
char c;
bool st;
void f(int nw) {
  if (x[nw] < x[nw - m])
    x[nw] = x[nw - m], st = 1;
  else if (x[nw] > x[nw - m]) {
    int id = nw - 1;
    x[nw] = 0;
    x[id]++;
    while (x[id] == 10) x[id - 1]++, x[id] = 0, --id;
    for (int i = id; i <= nw; ++i)
      if (i > m) f(i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> c;
    if (!st) x[i] = c - '0';
    if (i > m) f(i);
  }
  cout << n << '\n';
  for (int i = 1; i <= n; ++i) cout << x[i];
  cout << '\n';
  return 0;
}
