#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, k;
  cin >> n >> k;
  for (int i = 1; i < n - k; i++) cout << i << " ";
  for (int i = n; i > n - k; i--) cout << i << " ";
  cout << endl;
  return 0;
}
