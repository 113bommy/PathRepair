#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, n;
  long long int min1 = 100000000;
  long long int a[100005];
  long long int c = 0;
  int ans;
  string o;
  cin >> n >> k;
  cin >> o;
  for (int i = 0; i < o.size(); i++)
    if (o[i] == '0') {
      a[c] = i;
      c++;
    }
  long long int j = k;
  for (int i = 0; j < c; i++) {
    int m = (a[i] + a[j]) / 2;
    int m1 = lower_bound(a, a + c, m) - a + 1;
    min1 = min(min(min1, max(a[m1] - a[i], a[j] - a[m1])),
               max(a[m1 - 1] - a[i], a[j] - a[m1 - 1]));
    j++;
  }
  cout << min1;
  return 0;
}
