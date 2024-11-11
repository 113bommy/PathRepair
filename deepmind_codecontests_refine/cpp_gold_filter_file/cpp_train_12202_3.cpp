#include <bits/stdc++.h>
using namespace std;
void ram5564() {
  int n;
  cin >> n;
  int arr[n + 3], a[200003] = {0};
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    a[arr[i]] = i;
  }
  cout << 1;
  int Min = a[1], Max = a[1];
  for (int i = 2; i <= n; ++i) {
    Min = min(Min, a[i]);
    Max = max(Max, a[i]);
    if (Max - Min == (i - 1))
      cout << 1;
    else
      cout << 0;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) ram5564();
  return 0;
}
