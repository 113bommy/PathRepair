#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char x[n];
  scanf("%s", x);
  char dup[n];
  for (int i = 0; i < n; i++) dup[i] = x[i];
  sort(dup, dup + n);
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (x[i] != dup[i]) flag = true;
  }
  if (!flag)
    cout << "NO";
  else {
    cout << "YES" << endl;
    int pos, pos1;
    for (int i = 0; i < n - 1; i++) {
      if (x[i] > x[i + 1]) {
        pos = i, pos1 = i + 1;
        break;
      }
    }
    cout << pos << " " << pos1;
  }
  return 0;
}
