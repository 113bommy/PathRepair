#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int n, mn, c = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (i == 0) {
        mn = arr[i];
      } else {
        mn = min(mn, arr[i]);
      }
    }
    pair<int, int> p;
    p.second = mn;
    for (int i = 0; i < n; i++) {
      p.first = arr[i];
      if (p.first == p.second) {
        continue;
      } else if (c != n / 2) {
        c++;
        cout << p.first << " " << p.second << endl;
      }
    }
  }
  return 0;
}
