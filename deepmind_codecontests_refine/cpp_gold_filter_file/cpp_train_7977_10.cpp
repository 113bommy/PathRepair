#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int n, m, c = 0;
int cnt;
bool valid(int i) { return i >= 0 && i < n; }
vector<int> v[10000];
bool check() {
  for (int i = 1; i <= n; i++) {
    int c = 0;
    if ((int)v[i].size() != 0) {
      for (int k = 0; k < int(v[i].size()); k++) {
        if ((int)v[v[i][k]].size() == 0) c++;
      }
      if (c < 3) return false;
    }
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    v[x].push_back(i);
  }
  if (check())
    cout << "Yes\n";
  else
    cout << "No\n";
}
