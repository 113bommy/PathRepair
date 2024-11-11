#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
int a[maxn];
int n;
int main() {
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int k = 0;
  int ok = 0;
  int num = 0;
  for (int i = 0; i <= n; i++) {
    if (a[i] > 1)
      ok++;
    else
      ok = 0;
    if (ok == 2) num = i;
  }
  if (!num)
    cout << "perfect" << endl;
  else {
    cout << "ambiguous" << endl;
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= a[i]; j++) {
        cout << k << " ";
      }
      k += a[i];
    }
    cout << endl;
    k = 0;
    for (int i = 0; i <= n; i++) {
      if (i == num) {
        for (int j = 1; j < a[i]; j++) cout << k - 1 << " ";
        cout << k << " ";
      } else {
        for (int j = 1; j <= a[i]; j++) {
          cout << k << " ";
        }
      }
      k += a[i];
    }
    cout << endl;
  }
}
