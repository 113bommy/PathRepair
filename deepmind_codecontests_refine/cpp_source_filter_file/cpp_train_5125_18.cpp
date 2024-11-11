#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int x, m;
    cin >> x >> m;
    int arr[x];
    for (int i = 0; i < x; i++) {
      cin >> arr[i];
    }
    for (int i = 1; i < x; i++) {
      while (arr[i] > 0 && m > 0) {
        int ed = i;
        m -= ed;
        if (m > 0) {
          arr[0]++;
          arr[i]--;
        }
      }
    }
    cout << arr[0] << "\n";
  }
}
