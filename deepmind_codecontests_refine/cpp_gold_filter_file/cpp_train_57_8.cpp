#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str1, str2;
  cin >> str1 >> str2;
  int n;
  cin >> n;
  string str[2 * n];
  for (int i = 0; i < 2 * n; i = i + 2) cin >> str[i] >> str[i + 1];
  cout << str1 << " " << str2 << endl;
  for (int i = 0; i < 2 * n; i = i + 2) {
    if (str1 == str[i]) {
      cout << str2 << " " << str[i + 1];
      str1 = str[i + 1];
    } else {
      cout << str1 << " " << str[i + 1];
      str2 = str[i + 1];
    }
    cout << endl;
  }
  return 0;
}
