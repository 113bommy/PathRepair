#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  if (m <= n || n == 4) return cout << -1, 0;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<int> arr(n + 1);
  arr[n] = b;
  arr[n - 1] = d;
  arr[n - 3] = c;
  arr[1] = a;
  int j(2);
  for (int i = 1; i <= n; i++) {
    if (j == n - 3) j++;
    if (i != a && i != b && i != c && i != d) arr[j++] = i;
  }
  for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
  for (int i = n - 3; i >= 1; i--) cout << arr[i] << " ";
  cout << arr[n - 2] << " " << arr[n] << " " << arr[n - 1];
  return 0;
}
