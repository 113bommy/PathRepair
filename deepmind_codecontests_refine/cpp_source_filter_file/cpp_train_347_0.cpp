#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
const int m = 123123;
int n;
int a[m];
bool o1, o2;
int main() {
  ios::sync_with_stdio(false);
  scanf("%d", &n);
  for (int i = 1; i <= int(n); ++i) scanf("%d", &a[i]);
  for (int i = 2; i <= int(n); ++i)
    if (a[i] != a[i - 1]) {
      o1 = o2 = 1;
      swap(a[i], a[i - 1]);
      for (int j = 2; j <= int(n); ++j) {
        if (a[i - 1] > a[i]) o1 = 0;
        if (a[i - 1] < a[i]) o2 = 0;
        if (o1 || o2) continue;
        cout << i - 1 << ' ' << i << endl;
        return 0;
      }
      swap(a[i], a[i - 1]);
    }
  cout << "-1";
  return 0;
}
