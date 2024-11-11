#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char str[100010];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> str[i];
  if (n == 1)
    if (str == "1")
      cout << "NO";
    else
      cout << "YES" << endl << "0";
  else if (n == 2)
    if (str[1] == '1')
      cout << "NO";
    else if (str[0] == 0)
      cout << "NO";
    else
      cout << "YES\n1->0";
  else {
    if (str[n - 1] == '1')
      cout << "NO";
    else {
      if (str[n - 2] == '1') {
        cout << "YES" << endl;
        cout << "(";
        for (int i = 0; i < n - 2; i++) cout << str[i] << "->";
        cout << str[n - 2] << ")->" << str[n - 1];
      } else {
        for (int i = n - 3; i >= 0; i--) {
          if (str[i] == '0') {
            cout << "YES" << endl;
            for (int j = 0; j < i; j++) cout << str[j] << "->";
            cout << "(" << str[i] << "->(";
            for (int j = i + 1; j <= n - 3; j++) cout << str[j] << "->";
            cout << str[n - 2] << "))->" << str[n - 1];
            return 0;
          }
        }
        cout << "NO";
      }
    }
  }
  return 0;
}
