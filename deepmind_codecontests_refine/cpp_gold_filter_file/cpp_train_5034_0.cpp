#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N];
int main() {
  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), sum += a[i];
  if (sum % 3 != 0) {
    puts("0");
    return 0;
  }
  int val = sum / 3;
  map<int, int> mapeo;
  sum = 0;
  for (int i = n - 1; i >= 2; i--) {
    sum += a[i];
    mapeo[sum]++;
  }
  long long res = 0;
  int pos = 2, c = 0;
  for (int i = 0; i + 2 < n; ++i) {
    c += a[i];
    if (c == val) res += mapeo[val];
    mapeo[sum]--;
    sum -= a[pos++];
  }
  cout << res << endl;
  return 0;
}
