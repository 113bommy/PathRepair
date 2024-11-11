#include <bits/stdc++.h>
using namespace std;

int main() {
  int a , b , c , d;
  cin >> a >> b >> c >> d ;
  cout <<  ((abs(c - a)<=d ) || (abd(c-b)<=d && abs(b-a)<=d) ?
         "Yes" : "No" )
    << endl;
}