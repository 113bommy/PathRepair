#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, b, d;
  cin >> n >> b >> d;
  long long int* a = new long long int[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int juice = 0, count = 0;
  for (long long int i = 0; i < n; i++) {
    if (a[i] <= b) {
      juice += a[i];
    }
    if (juice > d) {
      juice = 0;
      count++;
    }
  }
  cout << count;
  return 0;
}
