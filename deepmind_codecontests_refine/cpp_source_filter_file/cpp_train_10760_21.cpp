#include <bits/stdc++.h>
using namespace std;
int a[1000000];
map<int, int> m;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    m[a[i]] = i;
  }
  for (int i = 1; i <= k; i++) {
    cout << a[i] << " ";
    int un = 1;
    for (int j = 1; j < n * k; j++) {
      if (un == n) {
        break;
      }
      if (m[j] == 0) {
        m[j] = i;
        cout << j << " ";
        un++;
      }
    }
    cout << endl;
  }
  cout << endl;
}
