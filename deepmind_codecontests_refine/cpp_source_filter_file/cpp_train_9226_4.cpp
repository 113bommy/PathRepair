#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int y, z;
    int flag = 0;
    for (int i = 0; i < 20; i++) {
      y = i * 7;
      z = x - y;
      if (z < 0) break;
      if (z % 3 == 0) {
        flag = 1;
      }
    }
    if (flag)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
