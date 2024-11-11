#include <bits/stdc++.h>
using namespace std;
double PI = 3.1415926536;
int dX[] = {1, -1, 0, 0};
int dY[] = {0, 0, 1, -1};
int n, m, k;
long long mem[5002][5002];
vector<long long> v, s;
long long Max_Sum(int idx, int c) {
  if (!c) return 0;
  long long &ret = mem[idx][c];
  if (ret != -1) return ret;
  if (idx + (c * m) > n + 1) return -1e18;
  return ret = max(Max_Sum(idx + 1, c),
                   Max_Sum(idx + m, c - 1) + s[idx + m - 1] - s[idx - 1]);
}
int main() {
  cin >> n >> m >> k;
  v.resize(n);
  s.resize(n + 1);
  memset(mem, -1, sizeof mem);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = (1); i < (n + 1); i++) s[i] = s[i - 1] + v[i - 1];
  cout << Max_Sum(0, k);
}
