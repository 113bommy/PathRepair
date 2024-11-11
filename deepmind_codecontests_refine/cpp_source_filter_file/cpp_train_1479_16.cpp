#include <bits/stdc++.h>
const double PI = 3.141592653589793238460;
using namespace std;
long long pows(long long a, long long n, long long m) {
  long long res = 1;
  while (n) {
    if (n % 2 != 0) {
      res = (res * a) % m;
      n--;
    } else {
      a = (a * a) % m;
      n = n / 2;
    }
  }
  return res % m;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool isprime(long long n) {
  if (n == 1) {
    return false;
  }
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
bool istrue(string s) {
  int i = 0;
  int j = s.size() - 1;
  while (i < j) {
    if (s[i] == s[j]) {
      i++;
      j--;
    } else {
      return false;
    }
  }
  return true;
}
long long n;
vector<long long> ar[100005];
long long col[100005][4];
int ans[100005];
long long isans() {
  long long res = -1;
  for (long long i = 1; i <= n; i++) {
    if (ar[i].size() >= 3) {
      return -1;
    } else if (ar[i].size() == 1) {
      res = i;
    }
  }
  return res;
}
long long dfs(int node, int par, int pc, int cc) {
  long long res = col[node][cc];
  for (int child : ar[node]) {
    if (child != par) {
      res += dfs(child, node, cc, 6 - pc - cc);
    }
  }
  return res;
}
void print(int node, int par, int pc, int cc) {
  ans[node] = cc;
  for (int child : ar[node]) {
    if (child != par) {
      print(child, node, cc, 6 - pc - cc);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> col[i][1];
  }
  for (long long i = 1; i <= n; i++) {
    cin >> col[i][2];
  }
  for (long long i = 1; i <= n; i++) {
    cin >> col[i][3];
  }
  int x, y;
  for (int i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    ar[x].push_back(y);
    ar[y].push_back(x);
  }
  long long code = isans();
  if (code == -1) {
    cout << -1 << endl;
    return 0;
  } else {
    pair<long long, long long> x;
    x = {1, 2};
    long long res = 1000000007;
    long long val = dfs(ar[code][0], code, 1, 2) + col[code][1];
    if (val < res) {
      res = val;
      x = {1, 2};
    }
    val = dfs(ar[code][0], code, 1, 3) + col[code][1];
    if (val < res) {
      res = val;
      x = {1, 3};
    }
    val = dfs(ar[code][0], code, 2, 1) + col[code][2];
    if (val < res) {
      res = val;
      x = {2, 1};
    }
    val = dfs(ar[code][0], code, 2, 3) + col[code][2];
    if (val < res) {
      res = val;
      x = {2, 3};
    }
    val = dfs(ar[code][0], code, 3, 1) + col[code][3];
    if (val < res) {
      res = val;
      x = {3, 1};
    }
    val = dfs(ar[code][0], code, 3, 2) + col[code][3];
    if (val < res) {
      res = val;
      x = {3, 2};
    }
    cout << res << endl;
    ans[code] = x.first;
    print(ar[code][0], code, x.first, x.second);
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
  }
}
