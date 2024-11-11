#include<bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, ct = 1; cin >> a >> b >> c;
  if(a != b) ct++; if(a != c && b != c) ct++;
  cout << ct << endl;
}