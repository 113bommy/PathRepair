#include <bits/stdc++.h>
using namespace std;
int n, i, j;
int main() {
  scanf("%d", &n);
  cout << (n * 3) + 4 << endl;
  cout << "1 1" << endl;
  cout << "1 2" << endl;
  for (i = 2; i <= n + 1; i++) {
    for (j = i - 1; j < i + 2; j++) cout << i << " " << j << endl;
  }
  cout << n + 2 << " " << n + 2 << endl;
  cout << n + 2 << " " << n + 3 << endl;
  return 0;
}
