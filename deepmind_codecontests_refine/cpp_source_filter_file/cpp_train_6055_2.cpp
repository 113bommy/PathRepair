#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
long long n, m, k;
char arr[100050];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  bool odd = false, even = false;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if ((arr[i] - '0') % 2 == 0)
      odd = true;
    else
      even = true;
  }
  if (odd && even) {
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
  } else {
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
  }
  return 0;
}
