#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n / 3; i++) printf("%d %d\n", 3, i * 2);
  for (int i = 1; i <= n - n / 3; i++) printf("%d %d\n", 0, i);
  return 0;
}
