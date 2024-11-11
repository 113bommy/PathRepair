#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int flag = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int num, num1;
    string str;
    cin >> str >> num >> num1;
    if (num >= 2400 && (num1 - num) > 0) {
      flag = 1;
      break;
    }
  }
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
