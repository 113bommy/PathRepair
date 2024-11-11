#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 5;
int arr[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int len = 1;
  int mx_len = 1, mx = 0, mn = 0;
  set<int> s;
  for (int i = 1; i <= n - 1; i++) {
    if (arr[i] <= arr[mn]) {
      mn = i;
    }
    if (arr[i] >= arr[mx]) {
      mx = i;
    }
    if (arr[mx] - arr[mn] <= 1) {
      len++;
    } else {
      s.insert(len);
      if (i == mx) {
        mn++;
        len = mx - mn + 1;
        mn = mx - 1;
      } else if (i == mn) {
        mx++;
        len = mn - mx + 1;
        mx = mn - 1;
      }
    }
  }
  s.insert(len);
  cout << *s.rbegin();
}
