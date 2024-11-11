#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
using namespace std;
int main() {
  (ios_base::sync_with_stdio(false), cin.tie(NULL));
  ;
  long long int n, m;
  cin >> n >> m;
  long long int a[n + 1];
  long long int b[n + 1];
  long long int k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  set<long long int> s;
  for (int i = n; i >= 1; i--) {
    s.insert(a[i]);
    b[i] = s.size();
  }
  for (int i = 0; i < n; i++) {
    cin >> k;
    cout << b[k] << "\n";
  }
}
