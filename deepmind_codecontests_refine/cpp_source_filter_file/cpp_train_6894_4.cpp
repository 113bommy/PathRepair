#include <bits/stdc++.h>
using namespace std;
void input(long long int n, long long int arr[]) {
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    cin >> arr[i];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    if (n == m * 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
