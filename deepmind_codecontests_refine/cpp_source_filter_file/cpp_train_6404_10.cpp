#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100], b[100];
  cin >> a >> b;
  int i = 0;
  while (i < (strlen(a))) {
    if (a[i] == b[i])
      cout << 0;
    else
      cout << 1;
    i++;
  }
  cout << endl;
  return 0;
}
