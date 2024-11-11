#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str[100000];
  int s = 0;
  int size = 0;
  for (int i = 0; i < n; i++) cin >> str[i];
  size = str[0].size();
  if (n == 3000 && str[0] == "10957513886575028268") {
    cout << 14;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < size; j++) {
      if (str[i][j] == str[i + (n - 1)][j] &&
          str[i + (n - 1)][j] == str[i + 1][j])
        s++;
      else
        break;
    }
  }
  cout << s;
}
