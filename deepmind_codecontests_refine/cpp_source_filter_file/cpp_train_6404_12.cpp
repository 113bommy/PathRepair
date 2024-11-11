#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100];
  char b[100];
  cin >> a;
  cin >> b;
  for (int i = 0; i < strlen(a); i++) {
    if (a[i] != b[i]) {
      cout << "1";
    } else {
      cout << "0";
    }
  }
  return 0;
}
