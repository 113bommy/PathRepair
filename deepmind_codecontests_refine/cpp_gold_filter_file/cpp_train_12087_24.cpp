#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n;
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (a == 1) flag = 0;
  }
  if (flag)
    cout << "EASY" << endl;
  else
    cout << "HARD" << endl;
  return 0;
}
