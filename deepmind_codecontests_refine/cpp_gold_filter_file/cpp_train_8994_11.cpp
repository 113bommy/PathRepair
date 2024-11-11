#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long oo = 1e18 + 1;
int n, m;
vector<int> v;
int main() {
  cin >> n >> m;
  int step;
  for (int i = 0; i < m; i++) {
    scanf("%d", &step);
    ;
    v.push_back(step);
    ;
  }
  sort(v.begin(), v.end());
  if (m == 0) return puts("YES"), 0;
  if (v[0] == 1 || v[m - 1] == n) return puts("NO"), 0;
  for (int i = 0; i < m - 2; i++) {
    if (v[i] + 1 == v[i + 1] && v[i] + 2 == v[i + 2]) return puts("NO"), 0;
  }
  puts("YES");
}
