#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a[100001];
  long long int n1, n2, k, m;
  long long int b[100001];
  int i, j, f = 0;
  cin >> n1 >> n2 >> k >> m;
  for (int i = 0; i < n1; i++) cin >> a[i];
  for (int i = 0; i < n2; i++) cin >> b[i];
  if (a[k - 1] < b[n2 - m - 1])
    cout << "YES\n";
  else
    cout << "NO\n";
}
