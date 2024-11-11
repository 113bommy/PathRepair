#include <bits/stdc++.h>
using namespace std;
int cheak[100000];
int main() {
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int tem = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!cheak[j] && a[i] == b[j]) {
        tem = 1;
        cout << a[i] << " ";
        break;
      }
    }
  }
  if (tem == 0) {
    printf("\n");
  }
}
