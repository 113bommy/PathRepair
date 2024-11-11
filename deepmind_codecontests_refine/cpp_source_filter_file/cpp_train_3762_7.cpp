#include <bits/stdc++.h>
using namespace std;
void useFileInput() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void setMyPrecision(int n) { cout << fixed << setprecision(n); }
bool test = 0;
bool fileInput = 0;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int i = 0, j = n - 1;
  unsigned long ans = 0;
  while (i < j) {
    int temp = arr[i] + arr[j];
    ans += (temp * temp);
    i++;
    j--;
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  if (fileInput) useFileInput();
  if (test) {
    int t;
    cin >> t;
    while (t--) solve();
  } else
    solve();
  return 0;
}
