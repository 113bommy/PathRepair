#include <bits/stdc++.h>
using namespace std;
int a[5000 + 10];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) cin >> a[i];
  bool flag = false;
  for (int i = 1; i < n; i++) {
    if (a[a[a[i]]] == i) {
      flag = true;
      break;
    }
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
