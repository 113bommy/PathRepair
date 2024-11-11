#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long n, t;
vector<vector<long long> > a;
vector<long long> met;
void dfs(long long k) {
  met[k] = 1;
  for (int i = 0; i < a[k].size(); i++) {
    if (met[a[k][i]] == 0) dfs(a[k][i]);
  }
}
long long nod(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return nod(b, a % b);
}
long long comp(long long a, long long b) { return nod(a, b); }
long long first(long long a, long long b) {
  if (a == b) return 0;
  if (a == 0) {
    if (b == 1)
      return -1;
    else
      return 1;
  }
  if (a == 1) {
    if (b == 2)
      return -1;
    else
      return 1;
  }
  if (a == 2) {
    if (b == 0)
      return -1;
    else
      return 1;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b;
  cin >> a >> b;
  long long y = 0;
  while (y < pow(10, 10)) y++;
  cout << a + b - 1;
}
