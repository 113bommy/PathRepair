#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 15;
int n;
int a[maxn];
int b[maxn];
int main() {
  cin >> n;
  for (int(i) = (1); (i) != (n + 1); (i)++) {
    scanf("%d", &a[i]);
    b[i] = b[i - 1] + a[i];
  }
  int max_inc = -1;
  for (int(i) = (1); (i) != (n + 1); (i)++) {
    for (int(j) = (i); (j) != (n + 1); (j)++) {
      int ones = b[j] - b[i - 1];
      int zeroes = j - i + 1 - ones;
      max_inc = max(max_inc, zeroes - ones);
    }
  }
  cout << b[n] + max_inc << endl;
  return 0;
}
