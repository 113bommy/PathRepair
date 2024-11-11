#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
const int M = 5e3 + 50;
int n, m, u, k, l, r, t;
int cnt, cnt1, cnt2, ans;
int mn = INT_MAX;
int mx = INT_MIN;
const int fx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int fy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int visited[N];
const int MOD = (1ll << 30);
const int mod = 1e9 + 7;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return abs(a.second) > abs(b.second);
}
bool cmp1(const pair<string, pair<int, int>> &a,
          const pair<string, pair<int, int>> &b) {
  return abs(a.second.first) < abs(b.second.first);
}
bool isPowerOfTwo(int n) { return (ceil(log2(n)) == floor(log2(n))); }
int makedigit(string n) {
  int res = 0;
  for (int i = 0; i < n.size(); i++) {
    res = res * 10 + (n[i] - '0');
  }
  return res;
}
string inttostrng(int a) {
  ostringstream temp;
  string str;
  temp << a;
  return temp.str();
}
void clearr(int vis[N], int n) {
  for (int i = 0; i < n; i++) {
    vis[i] = 0;
  }
}
long long pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % m;
    }
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
void solve() {
  cin >> n >> m;
  int i = 0;
  while (i <= 100000) {
    int rem = n % m;
    if (rem == 0) {
      cout << "Yes";
      return;
    }
    n += (n % m);
    i++;
  }
  cout << "No";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  t = 1;
  while (t--) {
    solve();
  }
}
