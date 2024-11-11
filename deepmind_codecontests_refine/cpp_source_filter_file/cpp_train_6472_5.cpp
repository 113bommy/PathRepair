#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const double pi = acos(-1.0);
const double eps = 1e-6;
const long long mod = 998244353;
const int maxn = 3002;
const int logn = 20;
string s[maxn];
int n, m;
int arr[maxn][maxn];
int rmin[maxn][maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int g, x, y, z, a, b;
  cin >> n >> m >> a >> b;
  cin >> g >> x >> y >> z;
  for (int i = 1; i <= (n); i++) {
    for (int j = 1; j <= (m); j++) {
      arr[i][j] = g;
      g = (g * 1LL * x + y) % z;
    }
  }
  for (int i = 1; i <= (n); i++) {
    deque<int> dq;
    for (int j = 1; j <= (m); j++) {
      while (!dq.empty() && arr[i][dq.back()] >= arr[i][j]) dq.pop_back();
      dq.push_back(j);
      if (j >= b) {
        rmin[i][j] = arr[i][dq.front()];
        if (j - dq.front() + 1 >= b) dq.pop_front();
      }
    }
  }
  long long tot = 0;
  for (int j = (b); j <= (m); j++) {
    deque<int> dq;
    for (int i = 1; i <= (n); i++) {
      while (!dq.empty() && arr[dq.back()][j] >= rmin[i][j]) dq.pop_back();
      dq.push_back(i);
      if (i >= a) {
        tot += rmin[dq.front()][j];
        if (i - dq.front() + 1 >= a) dq.pop_front();
      }
    }
  }
  cout << tot;
  return 0;
}
