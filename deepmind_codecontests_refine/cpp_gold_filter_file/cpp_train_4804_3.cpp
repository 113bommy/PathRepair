#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
  cin >> k;
  int to = 1999 - k % 1999;
  cout << 2000 << endl;
  for (int i = 1; i <= 1998; i++) printf("0 ");
  printf("%d %d", -to, (to + k) / 1999 + to);
  return 0;
}
