#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  for (i = 0; i < 15; i++) {
    if (arr[i] == n) break;
  }
  int m;
  cin >> m;
  if (i < 14) {
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
