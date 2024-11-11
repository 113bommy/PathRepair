#include <bits/stdc++.h>
using namespace std;
long long int n, m, k, l, cnt, a[1000000], b[1000000];
int main() {
  cin >> n >> m;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> l;
    a[l] = true;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> l;
    b[l] = true;
  }
  for (int i = 0; i < 10000; i++) {
    if (a[i % n] == true || b[i % m] == true) a[i % n] = true, b[i % m] = true;
  }
  for (int i = 0; i < n; i++)
    if (a[i] == true) cnt++;
  for (int i = 0; i < m; i++)
    if (b[i] == true) cnt++;
  if (cnt == n + m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
