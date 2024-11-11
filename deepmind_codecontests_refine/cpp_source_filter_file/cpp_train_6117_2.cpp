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
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!cheak[j] && b[i] == a[j]) {
        tem = 1;
        cout << b[i] << " ";
        break;
      }
    }
  }
  if (tem == 0) {
    printf("\n");
  }
}
