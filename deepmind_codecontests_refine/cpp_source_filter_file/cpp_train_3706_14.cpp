#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47};
  for (i = 0; i < 14; i++) {
    if (arr[i] == n) break;
  }
  int m;
  cin >> m;
  if (i < 13) {
    if (arr[i + 1] == m) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  } else {
    cout << "NO";
  }
  return 0;
}
