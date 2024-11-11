#include <bits/stdc++.h>
using namespace std;
int flag[100];
int a[100];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    flag[a[i]] = true;
  }
  for (int i = 0; i < k; i++) {
    cout << a[i] << ' ';
    int count = 1;
    for (int j = 1; count < n; j++)
      if (!flag[j]) {
        flag[j] = true;
        cout << j << ' ';
        count++;
      }
    cout << endl;
  }
  return 0;
}
