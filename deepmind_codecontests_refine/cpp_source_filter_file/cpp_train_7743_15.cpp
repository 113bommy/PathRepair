#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, block = 0, maxblock = 0;
  char *road;
  cin >> n >> k;
  road = (char *)malloc(n + 1);
  cin >> road;
  for (int i = 0; i < n; i++) {
    if (road[i] == '#') {
      block++;
    } else {
      if (!block) continue;
      if (block > maxblock) {
        maxblock = block;
      }
      block = 0;
    }
  }
  if ((maxblock > k) || (block > k))
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
