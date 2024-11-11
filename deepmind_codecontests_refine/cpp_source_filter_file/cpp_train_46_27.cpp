#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  list<long int> x, y, z;
  for (int i = 0; i < t; i++) {
    long int in;
    cin >> in;
    x.push_back(in);
  }
  x.sort();
  for (int i = 0; i < t - 1; i++) {
    long int in;
    cin >> in;
    y.push_back(in);
  }
  y.sort();
  list<long int>::iterator i1 = x.begin(), i2 = y.begin();
  while (*i1 == *i2 && i2 != x.end()) i1++, i2++;
  cout << *i1 << endl;
  for (int i = 0; i < t - 2; i++) {
    long int in;
    cin >> in;
    z.push_back(in);
  }
  z.sort();
  i1 = y.begin(), i2 = z.begin();
  while (*i1 == *i2 && i2 != y.end()) i1++, i2++;
  cout << *i1 << endl;
}
