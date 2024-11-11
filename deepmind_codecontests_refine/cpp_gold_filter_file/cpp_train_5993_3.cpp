#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, max = 0, num = 0;
  char string[300];
  cin >> n;
  cin >> string;
  int check = 0, length = 0;
  for (int i = 0; i < n; i++) {
    if (string[i] == '(')
      check = 1;
    else if (string[i] == ')')
      check = 0;
    if (check == 1) {
      length = 0;
      if ((string[i] >= 'a' && string[i] <= 'z') ||
          (string[i] >= 'A' && string[i] <= 'Z'))
        if (string[i + 1] == '_' || string[i + 1] == ')') num++;
    } else if (check == 0) {
      if ((string[i] >= 'a' && string[i] <= 'z') ||
          (string[i] >= 'A' && string[i] <= 'Z')) {
        length++;
        if (string[i + 1] == '(' || string[i + 1] == '_' || i == n - 1) {
          if (max < length) max = length;
          length = 0;
        }
      }
    }
  }
  cout << max << " " << num;
}
