#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 0};
int dy[] = {0, 1, -1};
long long mo = 1e9;
const long double P = 3.141592653589793238L;
void trust_your_self() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long fast_power(long long x, long long y) {
  long long p = 1;
  while (y) {
    if (y % 2 != 0) p = (p * x);
    y /= 2;
    x = (x * x);
  }
  return p;
}
long long convert_to_num(string x) {
  long long num = 0;
  for (int i = 0; i < x.size(); i++) {
    num *= 2;
    num += x[i] - '0';
  }
  return num;
}
long long com(long long n, long long x) {
  long long p = 1, p1 = 1;
  for (int i = n; i > n - x; i--) p = p * i;
  for (int i = 1; i <= x; i++) p1 = p1 * i;
  return (p / p1);
}
vector<vector<int> > v(101);
int visit[101] = {0}, c = 0;
void dfs(int num) {
  visit[num] = 1;
  for (int k = 0; k < v[num].size(); k++) {
    if (visit[v[num][k]] == 0) {
      dfs(v[num][k]);
    }
  }
}
map<long long, int> mp;
int main() {
  trust_your_self();
  int t;
  cin >> t;
  while (t--) {
    pair<int, int> p[100001];
    string x = "";
    int a = 0, b = 0, f = 1;
    int n, l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> l >> r;
      p[i] = {l, r};
    }
    sort(p, p + n);
    for (int i = 0; i < n;) {
      if (p[i].first - a > 0) {
        x += 'R';
        a++;
      } else if (p[i].second - b > 0) {
        x += 'U';
        b++;
      }
      if (p[i].first - a < 0 || p[i].second - b < 0) {
        f = 0;
        break;
      }
      if (p[i].first == a && p[i].second == b) i++;
    }
    if (f)
      cout << "YES\n" << x << "\n";
    else
      cout << "NO\n";
  }
  return 0;
}
