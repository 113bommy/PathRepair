#include <bits/stdc++.h>
using namespace std;
long long int n, m;
int main() {
  cin >> n >> m;
  long long int a[100001];
  long long int e = 0;
  long long int o = 0;
  long long int e2 = 0;
  long long int o2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2)
      o++;
    else
      e++;
  }
  long long int b[100001];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    if (b[i] % 2)
      o2++;
    else
      e2++;
  }
  cout << (min(o, e2) + min(o2, e));
}
