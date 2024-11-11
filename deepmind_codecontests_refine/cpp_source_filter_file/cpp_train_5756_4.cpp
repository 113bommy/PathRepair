#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << 2 << endl;
    if (n == 2) {
      cout << 1 << ' ' << 2 << endl;
      continue;
    }
    if (n == 3) {
      cout << 1 << ' ' << 2 << endl << 2 << ' ' << 2 << endl;
      continue;
    }
    cout << n << ' ' << n - 2 << endl << n - 1 << ' ' << n - 1 << endl;
    n--;
    while (n >= 3) {
      if (n == 3) {
        printf("1 3\n");
        break;
      }
      cout << n << ' ' << n - 2 << endl;
      n--;
    }
  }
}
