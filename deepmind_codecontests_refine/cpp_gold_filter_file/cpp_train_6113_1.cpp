#include <bits/stdc++.h>
using namespace std;
int n, m, key[10], fin[10];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> key[i];
  for (int i = 0; i < m; i++) cin >> fin[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (key[i] == fin[j]) cout << key[i] << " ";
  return 0;
}
