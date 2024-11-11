#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char a[105], b[105];
  cin >> a >> b;
  for (int i = 0; i < strlen(a); ++i) {
    if ((a[i] == '1' && b[i] == '1') || (a[i] == '0' && b[i] == '0'))
      cout << "0";
    else if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
      cout << "1";
  }
  return 0;
}
