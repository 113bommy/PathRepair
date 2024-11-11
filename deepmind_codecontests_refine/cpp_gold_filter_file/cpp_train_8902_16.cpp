#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, i, n, cond, con;
  cin >> num;
  char arr[num];
  for (i = 0; i < num; i++) cin >> arr[i];
  int ar[num];
  for (i = 0; i < num; i++) cin >> ar[i];
  cond = 0;
  con = 0;
  for (i = 0; i < num;) {
    con++;
    if (arr[i] == '>') {
      cond = cond + ar[i];
      i = ar[i] + i;
    } else if (arr[i] == '<') {
      cond = cond - ar[i];
      i = i - ar[i];
    }
    if (cond >= num || cond < 0) {
      cout << "FINITE" << endl;
      break;
    }
    if (con == num + 1) break;
  }
  if (con == num + 1) cout << "INFINITE" << endl;
  return 0;
}
