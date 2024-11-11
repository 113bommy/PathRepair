#include <bits/stdc++.h>
using namespace std;
long long int n, a, b;
long long int t[100007];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  long long int temp = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> t[i];
    if (t[i] < a) temp++;
  }
  if (a > b) {
    cout << n;
  } else {
    cout << temp / 2 + (temp % 2 == 1 ? 1 : 0);
  }
  return 0;
}
