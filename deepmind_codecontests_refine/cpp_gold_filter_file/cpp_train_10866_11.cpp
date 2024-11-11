#include <bits/stdc++.h>
using namespace std;
int arr[101000];
int main() {
  int m, n, a, b;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> arr[i];
  }
  int inc[101000], dec[101000];
  inc[m] = m;
  dec[1] = 1;
  for (int i = m - 1; i >= 1; i--) {
    if (arr[i] <= arr[i + 1])
      inc[i] = inc[i + 1];
    else
      inc[i] = i;
  }
  for (int i = 2; i <= m; i++) {
    if (arr[i] <= arr[i - 1])
      dec[i] = dec[i - 1];
    else
      dec[i] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (inc[a] >= dec[b])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
