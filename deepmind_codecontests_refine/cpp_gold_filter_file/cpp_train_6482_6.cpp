#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int i = 0;
    long long int count = 0;
    int x = -1;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < n; i++) {
      if (a[i] == 1) {
        count++;
      } else {
        x = i;
        break;
      }
    }
    if (x == -1) {
      if (count % 2 == 1) {
        cout << "First" << endl;
      } else {
        cout << "Second" << endl;
      }
    } else {
      if (x % 2 == 0) {
        cout << "First" << endl;
      } else {
        cout << "Second" << endl;
      }
    }
    x = -1;
  }
}
