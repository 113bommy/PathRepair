#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n < 6)
    cout << "-1" << endl;
  else {
    printf("1 2\n2 3\n2 4\n3 5\n3 6\n");
    for (int i = 7; i <= n; i++) cout << 3 << ' ' << i << endl;
  }
  for (int i = 2; i <= n; i++) {
    cout << i / 2 << ' ' << i << endl;
  }
  return 0;
}
