#include <bits/stdc++.h>
using namespace std;
int mat[500][500];
int main() {
  int a, b, r;
  cin >> a >> b >> r;
  a = min(a, b);
  if ((2 * r) <= a)
    cout << "First";
  else
    cout << "Second";
}
