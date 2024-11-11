#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long count = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      count = count + a[i - 1] - a[i];
    }
  }
  cout << count;
}
