#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 17;
const int inf = 1e9;
const int N = 2e5 + 5;
int n, m, x, y, z, ans[N];
vector<pair<int, int> > all;
vector<int> p;
char c;
long long t;
int main() {
  scanf("%d %d %lld", &n, &m, &t);
  int shift = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %c", &x, &c);
    x--;
    int sign = c == 'L' ? -1 : 1, need = sign == 1 ? m - x : x + 1;
    long long pos = x + sign * t;
    p.push_back((pos % m + m) % m);
    all.push_back(make_pair(x, i));
    shift += sign * t / m;
    if (t % m >= need) shift += sign;
  }
  shift = (shift % n + n) % n;
  sort(all.begin(), all.end());
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i++) ans[all[i].second] = p[(i + shift) % n];
  for (int i = 0; i < n; i++) printf("%d ", 1 + ans[i]);
  printf("\n");
  return 0;
}
