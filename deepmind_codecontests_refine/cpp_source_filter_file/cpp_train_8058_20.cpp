#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int a[n], l[m];
  set<long long int> s;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int i = n - 1; i >= 0; i--) {
    s.insert(a[i]);
    l[i] = s.size();
  }
  long long int x;
  for (int i = 0; i < m; i++) {
    cin >> x;
    cout << l[x - 1] << endl;
  }
}
