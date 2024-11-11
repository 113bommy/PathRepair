#include <bits/stdc++.h>
using namespace std;

int main() {
  int a , b , c , d;
  cin >> a >> b >> c >> d ;
  cout <<  ((abs(c - a)<=d ) || (abs(c-b)<=d && abs(b-a)<=d) ?
         "Yes" : "No" )
    << endl;
}