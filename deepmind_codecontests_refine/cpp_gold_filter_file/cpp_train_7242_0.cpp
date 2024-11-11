#include <bits/stdc++.h>
using namespace std;
int a[50];
int main() {
  string str;
  int cnt = 0;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'B')
      a[0]++;
    else if (str[i] == 'u')
      a[1]++;
    else if (str[i] == 'l')
      a[2]++;
    else if (str[i] == 'b')
      a[6]++;
    else if (str[i] == 'a')
      a[3]++;
    else if (str[i] == 's')
      a[4]++;
    else if (str[i] == 'r')
      a[5]++;
  }
  a[3] /= 2;
  a[1] /= 2;
  sort(a, a + 7);
  cout << a[0] << endl;
  return 0;
}
