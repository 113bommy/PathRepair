#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char str[N];
int main() {
  int a_o = 0, a_e = 0, b_o = 0, b_e = 0, even = 0, odd = 0;
  cin >> str;
  int n = (int)strlen(str);
  for (int i = n - 1; i >= 0; i--) {
    if (i % 2 == 0) {
      if (str[i] == 'a') {
        even += a_e;
        odd += a_o;
        a_e++;
      } else {
        even += b_e;
        odd += b_o;
        b_e++;
      }
    } else {
      if (str[i] == 'a') {
        even += a_o;
        odd += a_e;
        a_o++;
      } else {
        even += b_o;
        odd += b_e;
        b_o++;
      }
    }
  }
  even += n;
  cout << odd << " " << even << endl;
  return 0;
}
