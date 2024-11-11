#include <iostream>
#include<cmath>
 
using namespace std;
 
double EPS = 1e-10;
double pi = 3.1415926535;
 
double calc(int x) {
  return sin((double)x*pi/180.0);
}
  
 
int main(void){

  int n,m;
   
  while( cin >> n , n ){

    doubles1 = 0, s2 = 0, angle, c = 360;
    
    for( int i = 0 ; i < n - 1 ; i++ ){
      cin >> angle;
      c -= angle;
      s1 += calc(angle);
    }
    s1 += calc(c);

    cin >> m;
    s = 360;

    for( int j = 0 ; j < m - 1 ; j++ ){
      cin >> angle;
      c -= angle;
      s2 += calc(angle);
    }
    s2 += calc(c);

    if( s1 > s2 + EPS ) cout << 1 << endl;
    else if( s1 + EPS < s2 ) cout << 2 << endl;
    else cout << 0 << endl;
  }
 
  return 0;
}