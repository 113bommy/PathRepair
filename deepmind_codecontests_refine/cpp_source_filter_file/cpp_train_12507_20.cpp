#include <bits/stdc++.h>
using namespace std;
int main() {
  int test, tc = 0, a, b = 0, n;
  int ar[105], br[105];
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &ar[i], &br[i]);
  }
  cin >> a;
  a--;
  for (int i = 0; i < n; i++) {
    if (br[i] <= a) b++;
  }
  cout << b << endl;
  return 0;
}
