#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, a, b, n, s, ar1[100001], ar2[100001];
  cin >> n >> s;
  char ch;
  for (i = 0; i < 100001; i++) {
    ar1[i] = 0;
    ar2[i] = 0;
  }
  for (i = 0; i < n; i++) {
    cin >> ch;
    cin >> a >> b;
    if (ch == 'B')
      ar1[a] += b;
    else if (ch == 'S')
      ar2[a] += b;
  }
  a = 0;
  for (i = 0; i < 100001; i++) {
    if (a >= s) break;
    if (ar2[i] != 0) {
      a++;
    }
  }
  if (i <= 100000)
    a = i - 1;
  else
    a = 100000;
  for (i = a; i > 0; i--) {
    if (ar2[i] != 0) {
      cout << "S " << i << " " << ar2[i] << endl;
      a++;
    }
  }
  a = 0;
  for (i = 100000; i >= 0; i--) {
    if (a >= s) break;
    if (ar1[i] != 0) {
      cout << "B " << i << " " << ar1[i] << endl;
      a++;
    }
  }
  return 0;
}
