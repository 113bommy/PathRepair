#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int count = 0, num = INT_MIN;
    long long int maxn = *max_element(a, a + n);
    if (a[n - 1] == maxn) {
      cout << "0\n";
    } else {
      for (int i = n - 1; i >= 0; i--) {
        if (a[i] == maxn) {
          break;
        } else if (a[i] > num) {
          count++;
          num = a[i];
        }
      }
      cout << count << endl;
    }
  }
}
