#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int mx = 1;
  for (int i = 0; i < n; i++) {
    int pos = i;
    int cnt = 1;
    for (int j = pos; j > 0; j--) {
      if (ar[j] >= ar[j - 1]) {
        cnt++;
      } else {
        break;
      }
    }
    for (int j = pos; j < n; j++) {
      if (ar[j] >= ar[j + 1]) {
        cnt++;
      } else {
        break;
      }
    }
    mx = max(mx, cnt);
  }
  cout << mx << endl;
}
