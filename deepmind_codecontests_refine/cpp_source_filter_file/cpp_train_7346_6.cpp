#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
const long long inf = 0x3f3f3f3f;
int main() {
  int n;
  cin >> n;
  int i = 0, sum = 0;
  while (sum < n) {
    i++;
    sum += i;
  }
  i--;
  cout << i << endl;
  int t = i * (i - 1) / 2;
  for (int(j) = (1); (j) < (i); (j)++) cout << j << " ";
  cout << n - t;
  return 0;
}
