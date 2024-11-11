#include <bits/stdc++.h>
using namespace std;
int i, s, v[300001], n;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> v[i];
  sort(v, v + n + 1);
  for (i = 1; i <= n; i++) s += (i + 1) * v[i];
  cout << s - v[n];
}
