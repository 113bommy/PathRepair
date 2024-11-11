#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int* degree = new int[100005];
  for (int i = 1; i <= n; i++) {
    degree[i] = 0;
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    degree[a]++;
    degree[b]++;
  }
  int deg1 = 0, deg2 = 0, degG = 0;
  for (int i = 1; i <= n; i++) {
    if (degree[i] == 0) {
      continue;
    } else if (degree[i] == 1) {
      deg1++;
    } else if (degree[i] == 2) {
      deg2++;
    } else if (degree[i] == n - 1) {
      degG++;
    }
  }
  if (deg1 == n - 1 && deg2 == 0 && degG == 1) {
    cout << "star topology";
    return 0;
  } else if (deg1 == 2 && deg2 > 1 && degG == 0) {
    cout << "bus topology";
    return 0;
  } else if (deg1 == 0 && deg2 == n && degG == 0) {
    cout << "ring topology";
    return 0;
  } else {
    cout << "unknown topology";
  }
  return 0;
}
