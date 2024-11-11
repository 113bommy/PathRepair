#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[10004];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int d[10004] = {0};
  int check = 1;
  int tmp = 1;
  int dem = 0;
  for (int i = 1; i <= n; i++) {
    d[i] = 1;
    while (tmp <= i) {
      if (d[a[tmp]] == 0) {
        check = 0;
        break;
      }
      tmp++;
    }
    if (check == 1) {
      tmp = i + 1;
      dem++;
    }
    if (check == 0) check = 1;
  }
  cout << dem << endl;
  return 0;
}
