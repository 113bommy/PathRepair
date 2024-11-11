#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string my_str[n];
  for (int i = 0; i < n; i++) {
    cin >> my_str[i];
  }
  string result = "";
  for (int row = 0; row < n; row++) {
    for (int column = 0; column < m; column++) {
      bool found_row = false;
      bool found_column = false;
      for (int i = 0; i < m; i++) {
        if ((my_str[row][column] == my_str[row][i]) && (i != column))
          found_row = true;
      }
      for (int j = 0; j < n; j++) {
        if ((my_str[row][column] == my_str[j][column]) && (j != row))
          found_column = true;
      }
      if ((found_row == false) && (found_column == false))
        result += my_str[row][column];
    }
  }
  cout << result;
  return 0;
}
