#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
 int d,e,x,y;
 while(cin >> d >> e && d){
  float ans;
  ans = 1e6;
  for(x=0;x<=d;x++){
   y = d-x;
   ans = min(fabs(sqrt(x*x+y*y)-e),ans);
  }
  cout << ans << endl;
 }
 return 0;
}
   
