#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100], b[100], c[100];
  int n, k, coun = 1;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cin >> b[i];
  }
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j] || (a[i] == a[j] && b[i] < b[j])) {
        int temp, temp2;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        temp2 = b[i];
        b[i] = b[j];
        b[j] = temp2;
      }
    }
  int tempu = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == a[i + 1] && b[i] == b[i + 1])
      coun++;
    else {
      for (int j = tempu; j <= i; j++) {
        c[j] = coun;
      }
      tempu = i + 1;
      coun = 1;
    }
  }
  cout << c[k - 1];
}
