#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string str[n];
  int a[5];
  int arr[m];
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  int sum = 0;
  for (int j = 0; j < 5; j++) a[j] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 5; j++) a[j] = 0;
    for (int j = 0; j < n; j++) {
      if (str[j][i] == 'A')
        a[0]++;
      else if (str[j][i] == 'B')
        a[1]++;
      else if (str[j][i] == 'C')
        a[2]++;
      else if (str[j][i] == 'D')
        a[3]++;
      else
        a[4]++;
    }
    int ma = 0, index = 0;
    for (int j = 0; j < 5; j++) {
      if (a[j] > ma) {
        ma = a[j];
        index = j;
      }
    }
    sum = sum + ma * arr[index];
  }
  cout << sum;
}
