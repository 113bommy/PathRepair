#include <bits/stdc++.h>
using namespace std;
int v[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  sort(v + 1, v + n + 1);
  if (v[n] != 1) {
    v[n] = 1;
  } else
    v[n] = 2;
  sort(v + 1, v + n + 1);
  for (int i = 1; i <= n; i++) cout << v[i] << " ";
  return 0;
}
