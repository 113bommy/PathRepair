#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arrx[105];
  int arr[105];
  int temp1 = 0;
  int temp2 = 1;
  int counter1 = 0;
  int x;
  for (int j = 0; j < m; j++) arr[j] = temp1;
  for (int i = 0; i < n; i++) {
    counter1 = 0;
    cin >> x;
    for (int k = 0; k < x; k++) {
      cin >> arrx[k];
      arr[arrx[k]] = temp2;
    }
  }
  for (int k = 0; k < x; k++) {
    if (arrx[k] == temp2) counter1++;
  }
  if (counter1 == m)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
