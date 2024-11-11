#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, v0, v1, a, l, temp = 0, p = 1;
  cin >> c >> v0 >> v1 >> a >> l;
  temp = v0;
  while (temp < c) {
    if (v0 < v1) v0 = v0 + a;
    if (v0 >= v1) v0 = v1;
    temp = temp + v0 - l;
    c++;
  }
  cout << p;
}
