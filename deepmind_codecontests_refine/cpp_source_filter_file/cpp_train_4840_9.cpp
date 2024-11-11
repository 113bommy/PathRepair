#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main() {
  int n;
  int count = 0, t = 0;
  int car[100];
  bool flag;
  cin >> n;
  for (int i = 0; i < n; i++) {
    flag = true;
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0)
        count++;
      else if (a[i][j] == 1 || a[i][j] == 3)
        flag = false;
    }
    if (flag == true) car[t] = i + 1, t++;
  }
  cout << count / 2 << endl;
  for (int i = 0; i < t; i++) cout << car[i] << " ";
  return 0;
}
