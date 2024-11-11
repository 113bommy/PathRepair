#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int Maxn = 10010;
int a[Maxn];
int tot = 0;
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 2 * i; j <= n; j++) {
      sum += 4ll * (j / i);
    }
  }
  cout << sum << endl;
  return 0;
}
