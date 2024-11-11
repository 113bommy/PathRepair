#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    bool possible = 1;
    int a[n], b[n];
    map<pair<int, int>, int> pairs;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    if (n % 2 == 1 && a[n / 2] != b[n / 2]) possible = 0;
    for (int i = 0; i < n / 2; i++) {
      pair<int, int> p = {min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])};
      pairs[p]++;
    }
    for (int i = 0; i < n / 2; i++) {
      pair<int, int> p = {min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1])};
      if (pairs[p] == 0) {
        possible = 0;
        break;
      }
      pairs[p]--;
    }
    cout << (possible ? "Yes" : "No") << endl;
  }
}
