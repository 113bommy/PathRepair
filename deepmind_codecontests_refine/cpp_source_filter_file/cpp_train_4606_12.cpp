#include <bits/stdc++.h>
using namespace std;
void solve() {
  int arr[7];
  int n;
  cin >> n;
  int j = 6;
  while (n) {
    int rem = n % 2;
    arr[j] = rem;
    n = n / 2;
    j--;
  }
  int temp = arr[2];
  arr[2] = arr[6];
  arr[6] = temp;
  temp = arr[3];
  arr[3] = arr[4];
  arr[4] = temp;
  int ans = 0;
  for (int i = 1; i < 7; i++) ans = ans * 2 + arr[i];
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
