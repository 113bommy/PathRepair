#include <bits/stdc++.h>
using namespace std;
int main() {
  string m[12] = {"January",   "February", "March",    "April",
                  "May",       "June",     "July",     "August",
                  "September", "October",  "December", "November"};
  string s;
  int k, d;
  cin >> s >> k;
  for (int i = 0; i < 12; i++)
    if (s == m[i]) d = i;
  int kq = (k + d) % 12;
  cout << m[kq];
}
