#include <bits/stdc++.h>
using namespace std;
long long int itre;
int main() {
  long long int n;
  int m, flag = 0;
  cin >> n >> m;
  long long int arr[m + 2];
  arr[0] = 1;
  arr[m + 1] = n;
  for (int i = 1; i < m + 1; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + m + 2);
  int i = 1;
  if (arr[1] == 1 || arr[m] == n)
    cout << "NO";
  else {
    for (int i = 1; i < m + 2; i = i + 1) {
      if (arr[i + 1] - arr[i] == 1) {
        if (arr[i + 2] - arr[i] == 2 && arr[i + 2] != arr[m + 1]) {
          cout << "NO" << endl;
          flag = 1;
          break;
        } else {
          itre = arr[i + 1] + 1;
        }
      } else {
        itre = arr[i + 1] - 1;
      }
    }
    if (flag == 0) cout << "YES";
  }
}
