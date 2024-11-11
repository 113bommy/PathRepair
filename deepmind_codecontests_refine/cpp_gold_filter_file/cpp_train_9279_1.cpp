#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  y = y - (n - 1);
  if (y * y + (n - 1) < x || y <= 0)
    printf("-1");
  else {
    cout << y << " ";
    for (int i = 0; i < n - 1; i++) printf("1 ");
  }
}
