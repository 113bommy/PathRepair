#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, v, cost = 0;
  cin >> n >> v;
  if (n > v)
    cost += v;
  else
    cost += n - 1;
  for (int i = 2; i <= n - v; i++) {
    cost += i;
  }
  cout << cost << endl;
  return 0;
}
