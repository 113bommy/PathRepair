#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  printf("%d\n", n);
  for (int i = 1; i < n; i++) printf("%d ", n - i);
  puts("");
  return 0;
}
