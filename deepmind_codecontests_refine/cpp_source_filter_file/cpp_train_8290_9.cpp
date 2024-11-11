#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  string p;
  char q[10];
  cin >> s;
  char arr[10][10];
  int i;
  for (i = 0; i < 10; i++) cin >> arr[i];
  int j;
  for (j = 0; j < 8; j++) {
    p = s.substr(j * 10, 10);
    strcpy(q, p.c_str());
    for (i = 0; i < 10; i++) {
      if (strcmp(q, arr[i]) == 0) {
        cout << i;
        break;
      }
    }
  }
}
