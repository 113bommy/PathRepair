#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, N;
  char line[300];
  int op[300];
  cin >> line;
  for (i = 0, j = 0; line[i] != '\0'; i++, j++) {
    if (line[i] == '-') {
      if (line[i + 1] == '-') {
        op[j] = 2;
        i++;
      } else if (line[i + 1] == '.') {
        op[j] = 1;
        i++;
      }
    } else if (line[i] == '.')
      op[j] = 0;
    cout << op[j];
  }
  return 0;
}
