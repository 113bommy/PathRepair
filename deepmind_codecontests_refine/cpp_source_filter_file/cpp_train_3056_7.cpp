#include <bits/stdc++.h>
using namespace std;
int main() {
  char dir[100 + 1], temp[100 + 1];
  int n, m = 0;
  cin.get(dir, 100 + 1, '\n');
  n = strlen(dir);
  for (int i = 0; i < n; ++i)
    if (dir[i] != '/' || m == 0 || temp[m - 1] != '/') temp[m++] = dir[i];
  if (m > 0 && temp[m - 1] == '/') m -= 1;
  temp[m] = '\0';
  cout << temp;
}
