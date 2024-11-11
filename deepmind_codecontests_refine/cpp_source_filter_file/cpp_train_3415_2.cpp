#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  
  int c = a + b - 1;
  int sum = ( b + c ) * a / 2
  if ( c < 0 ) {
    sum -= c;
  } else if ( 0 < b ) {
    sum -= b;
  }
  cout << sum << endl;
}