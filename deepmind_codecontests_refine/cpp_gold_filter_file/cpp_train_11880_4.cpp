#include <bits/stdc++.h>
using namespace std;
int n, val[200005];
void DFS(int n) {
  if (n != 1) DFS(val[n]);
  cout << n << " ";
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; ++i) cin >> val[i];
  DFS(n);
}
