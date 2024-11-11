#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int A[n][n];
  int i = 0, j = 0, count = 0;
  bool b = true;
  list<int> temp;
  for (i = 0; i < n; i++) {
    b = true;
    for (j = 0; j < n; j++) {
      cin >> A[i][j];
      if (A[i][j] == 1 || A[i][j] == 3) {
        b = false;
      }
    }
    if (b) {
      count++;
      temp.push_back(i + 1);
    }
  }
  cout << count << endl;
  for (list<int>::iterator it = temp.begin(); it != temp.end(); ++it) {
    cout << *it << "";
  }
  return 0;
}
