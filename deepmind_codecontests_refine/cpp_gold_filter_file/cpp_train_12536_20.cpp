#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
long double PI = 3.14159265358979323846264338327950;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  reverse(v.begin(), v.end());
  long long c = 0, res = 0;
  for (auto i : v) {
    if (!i)
      c++;
    else
      res += c;
  }
  cout << res;
  return 0;
}
