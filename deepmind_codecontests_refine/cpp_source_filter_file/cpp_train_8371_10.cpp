#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[1000];
  long long n, i, j, u = 1, t = 0;
  cin >> a;
  n = strlen(a);
  for (i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1])
      u++;
    else {
      if (u % 2 == 0) {
        u = 1;
        t++;
      } else
        u = 1;
    }
  }
  cout << t << endl;
}
