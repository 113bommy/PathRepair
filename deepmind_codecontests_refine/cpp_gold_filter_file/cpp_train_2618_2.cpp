#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b;
  int i, j;
  cin >> a >> b;
  if (b % a != 0)
    cout << "-1" << endl;
  else {
    for (i = 1;; i++) {
      if ((int)(b / a) % (int)pow(2, i) != 0) break;
    }
    i -= 1;
    for (j = 1;; j++) {
      if ((int)(b / a) % (int)pow(3, j) != 0) break;
    }
    j -= 1;
    if (pow(2, i) * pow(3, j) * a != b)
      cout << "-1" << endl;
    else
      cout << i + j << endl;
  }
}
