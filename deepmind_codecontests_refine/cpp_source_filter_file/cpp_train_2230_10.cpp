#include <bits/stdc++.h>
using namespace std;
int n, x;
int main() {
  scanf("%d", &n);
  int s = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x)
      c++;
    else
      s += c;
  }
  cout << s << endl;
  return 0;
}
