#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,s,e;
  cin >> a >> b >> c >> d;
  s= max(a,c);
  e=min(b,d);
  cout << (e-s>0 ? e-s : 0) << endl;