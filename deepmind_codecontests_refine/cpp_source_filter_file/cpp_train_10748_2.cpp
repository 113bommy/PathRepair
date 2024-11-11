#include <bits/stdc++.h>
using namespace std;
int arr[1010];
int n, x;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    int oddnum = 0;
    int even = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] % 2) oddnum++;
    }
    even = n - oddnum;
    bool flag = false;
    for (int i = 1; i <= n; i += 2) {
      if (i <= oddnum && x - i <= even) {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
