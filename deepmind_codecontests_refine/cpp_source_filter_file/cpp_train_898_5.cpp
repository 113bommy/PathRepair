#include <bits/stdc++.h>
using namespace std;
int a, b, n;
string s;
int main() {
  cin >> n;
  int m = n;
  while (n--) {
    cin >> s;
    cin >> s;
    if (s == "hard") {
      a++;
    } else {
      b++;
    }
  }
  a = max(a, b);
  double tmp = (double)a;
  tmp = tmp * 2;
  tmp = tmp - 1;
  tmp = ceil(sqrt(tmp));
  if (tmp * tmp < n) tmp = tmp + 1;
  printf("%.0lf", tmp);
}
