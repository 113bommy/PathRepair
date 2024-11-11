#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int now = 1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1) {
        if (i == n) {
          break;
        } else {
          now = 3 - i;
        }
      } else {
        break;
      }
    }
    if (now == 1)
      cout << "First\n";
    else
      cout << "Second\n";
  }
}
