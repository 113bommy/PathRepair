#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, k = 0;
  char dist[26];
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    dist[i] = i + 97;
  }
  for (int i = 0; i < n; i++) {
    int x = i / k;
    if (x == 0)
      cout << dist[i];
    else
      cout << dist[i - x * k];
  }
  return 0;
}
