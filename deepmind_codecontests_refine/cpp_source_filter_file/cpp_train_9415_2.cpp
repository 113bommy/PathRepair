#include <bits/stdc++.h>
using namespace std;
void bla() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int main() {
  bla();
  int n, d;
  cin >> n >> d;
  int arr[n];
  long long s = 0;
  for (int i = 0; i < int(n); i++) cin >> arr[i], s += arr[i];
  long long sum = 5, i = 0, c = 0, c1 = 0, mx = 1;
  while (i < n) {
    if (c == c1) {
      if (sum + arr[i] <= d)
        sum += arr[i], c++;
      else
        return cout << -1, 0;
      i++;
    } else {
      if (sum + 10 < d)
        sum += 10, c1++, mx += 2;
      else
        return cout << -1, 0;
    }
  }
  cout << mx + (d - sum) / 5;
}
