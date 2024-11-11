#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[1000], b[1000];
  int c, f = 0;
  cin >> a;
  cin >> b;
  if (strlen(a) != strlen(b))
    cout << "NO";
  else {
    for (int i = 0; i < strlen(a); i++)
      if (a[i] != b[strlen(a) - 1 - i]) f = 1;
    if (f == 1)
      cout << "NO";
    else
      cout << "YES";
  }
}
