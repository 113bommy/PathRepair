#include <bits/stdc++.h>
const double EULER = 0.57721566490153286060651209;
const double PI = 3.14159265358979323846264338328;
const double E = 2.718281828459045235360287471352;
using namespace std;
string a, b;
int main() {
  cin >> a >> b;
  int len = a.size();
  a[len - 1]++;
  for (int i = len - 1; i > -1; i--) {
    if (a[i] == 'z' + 1) {
      a[i] = 'a';
      a[i - 1]++;
    } else {
      break;
    }
  }
  if (a != b) {
    cout << a << endl;
  } else {
    cout << "No such string" << endl;
  }
  return 0;
}
