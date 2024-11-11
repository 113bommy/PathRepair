#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int arr[30] = {}, n, i = 0;
  cin >> n;
  while (n > 0) arr[i] = n % 2, n /= 2, i++;
  for (i = 29; i >= 0; i--)
    if (arr[i]) cout << i << ' ';
  cout << '\n';
  return 0;
}
