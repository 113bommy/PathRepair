#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const long long INF64 = (long long)1e18;
#pragma comment(linker, "/STACK:16777216")
#pragma warning(disable : 4786)
int Set(int N, int pos) { return N = N | (1 << pos); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
const int mx = 1 << 29;
int ans, sum, t, n, k, m, tk[100005], ar[100005];
string s;
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
int f(int id) {
  if (tk[id]) return 0;
  tk[id] = 1;
  if (s[id] == '<') {
    int jd = id - ar[id];
    if (jd < 0) return 1;
    return f(jd);
  }
  if (s[id] == '>') {
    int jd = id + ar[id];
    if (jd >= n) return 1;
    return f(jd);
  }
}
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
  ans = f(1);
  if (!ans)
    cout << "INFINITE\n";
  else
    cout << "FINITE\n";
  return 0;
}
