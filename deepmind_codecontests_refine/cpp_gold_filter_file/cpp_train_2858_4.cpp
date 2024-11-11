#include <bits/stdc++.h>
using namespace std;
int main() {
  string a[100];
  a[1] = "January";
  a[2] = "February";
  a[3] = "March";
  a[4] = "April";
  a[5] = "May";
  a[6] = "June";
  a[7] = "July";
  a[8] = "August";
  a[9] = "September";
  a[10] = "October";
  a[11] = "November";
  a[12] = "December";
  string b;
  char c[100];
  int n;
  int x;
  cin >> c;
  cin >> n;
  b = c;
  int i;
  for (i = 1; i < 13; i++)
    if (b == a[i]) x = i;
  x += n;
  while (x > 12) x -= 12;
  cout << a[x] << endl;
  return 0;
}
