#include <bits/stdc++.h>
using namespace std;
int n1, n2;
vector<int> v1, v2;
int k, m;
int main() {
  cin >> n1 >> n2;
  cin >> k >> m;
  v1.resize(n1);
  v2.resize(n2);
  for (int i = 0; i < n1; i++) cin >> v1[i];
  for (int i = 0; i < n2; i++) cin >> v2[i];
  bool ok = 1;
  for (int i = 0; i < m; i++) {
    if (v1[k - 1] > v2[n2 - 1 - i]) ok = 0;
  }
  if (ok)
    puts("YES");
  else
    puts("NO");
}
