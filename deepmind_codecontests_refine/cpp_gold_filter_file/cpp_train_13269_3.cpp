#include <bits/stdc++.h>
using namespace std;
long long n, d, a[100001], b[100001];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (int i = 2; i <= 100000; i++) {
    if (b[i] > b[i - 1]) {
      cout << "-1";
      return 0;
    }
  }
  cout << b[1] << "\n";
  for (int i = 0; i < n; i++) {
    b[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    cout << b[a[i]] << " ";
    b[a[i]]++;
  }
  return 0;
}
