#include <bits/stdc++.h>
using namespace std;
long long a, s, d, f, g, h, j, k, l, i, n, m;
vector<int> v;
string x;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (x[0] == 'a') {
      scanf("%d", &a);
      v.insert(lower_bound(v.begin(), v.end(), a), a);
    }
    if (x[0] == 'd') {
      scanf("%d", &a);
      v.erase(lower_bound(v.begin(), v.end(), a));
    }
    if (x[0] == 's') {
      for (a = 2; a < v.size(); a += 5) k = k + v[a];
      printf("%I64d\n", k);
      k = 0;
    }
  }
}
