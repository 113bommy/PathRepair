#include <bits/stdc++.h>
using namespace std;
char kk[20] = "8()[]<";
int main() {
  ios::sync_with_stdio(false);
  char a[100], b[100];
  while (cin >> a >> b) {
    int n = strlen(a);
    int key = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '8' && b[i] == '[' || (a[i] == '<' && b[i] == ']')) key++;
      if (a[i] == '[' && b[i] == '8' || (a[i] == ']' && b[i] == '<')) key--;
      if (a[i] == '[' && b[i] == '(' || (a[i] == ']' && b[i] == ')')) key++;
      if (a[i] == ')' && b[i] == ']' || (a[i] == '(' && b[i] == '[')) key--;
      if (a[i] == '8' && b[i] == '(' || (a[i] == '<' && b[i] == ')')) key++;
      if (a[i] == '(' && b[i] == '8' || (a[i] == ')' && b[i] == '<')) key--;
    }
    memset(a, '\0', sizeof(a));
    memset(b, '\0', sizeof(b));
    if (key == 0)
      cout << "TIE" << endl;
    else if (key < 0)
      cout << "TEAM 2 WINS" << endl;
    else if (key > 0)
      cout << "TEAM 1 WINS" << endl;
  }
  return 0;
}
