#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, z, k, sol, sum, ans, l, r, xx, yy, ca[1000000],
    b[1000000];
vector<long long> v;
vector<long long> v1;
vector<long long> v2;
pair<long long, pair<long long, long long> > pp[1000000];
pair<long long, long long> a[1000000];
map<long long, long long> ma;
string s1, s2, s;
char c;
void dfs(long long no) {
  if (ma[no]) return;
  ma[no] = 1;
  for (int i = 0; i < n; i++) {
    if ((a[i].first == a[no].first || a[i].second == a[no].second)) {
      dfs(i);
    }
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < n; i++) {
    if (ma[i]) continue;
    sum++;
    dfs(i);
  }
  cout << sum - 1 << endl;
  return 0;
}
