#include <bits/stdc++.h>
using namespace std;
int a[100005], cum[100005];
int main() {
  int n, c = 0;
  cin >> n >> a[0];
  cum[0] = a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    cum[i] = a[i] + cum[i - 1];
  }
  for (int i = 0; i < n - 1; i++)
    if (cum[i] == (cum[n] - cum[i])) c++;
  cout << c;
  return 0;
}
