#include <bits/stdc++.h>
using namespace std;
char a[1000 + 10][15];
char b[1000 + 10][15];
char c1[15], c2[15];
int main() {
  int n;
  cin >> c1 >> c2;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  for (int i = 0; i <= n; i++) {
    cout << c1 << " " << c2 << endl;
    if (strcmp(c1, a[i]) == 0)
      strcpy(c1, b[i]);
    else
      strcpy(c2, b[i]);
  }
  return 0;
}
