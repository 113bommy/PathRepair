#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, k, i, j, x;
int a[N], v[N];
string dict[N], cuv;
unordered_map<string, int> minim;
int main() {
  cin >> n >> k >> m;
  for (i = 1; i <= n; i++) cin >> dict[i];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    minim[dict[i]] = a[i];
  }
  for (i = 1; i <= k; i++) {
    cin >> x;
    int MIN = 1020000000;
    for (j = 1; j <= x; j++) {
      cin >> v[j];
      if (a[v[j]] < MIN) MIN = a[v[j]];
    }
    for (j = 1; j <= x; j++)
      if (MIN < minim[dict[v[j]]]) minim[dict[v[j]]] = MIN;
  }
  long long sol = 0;
  for (i = 1; i <= m; i++) {
    cin >> cuv;
    sol += minim[cuv];
  }
  cout << sol;
  return 0;
}
