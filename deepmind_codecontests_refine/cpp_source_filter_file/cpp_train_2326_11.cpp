#include <bits/stdc++.h>
using namespace std;
void faster() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int d, n, a[2345], sum;
int main() {
  cin >> d >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    sum += (d - a[i]);
  }
  cout << sum;
  return 0;
}
