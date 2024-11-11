#include <iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n,n){
    int a,b,c,d,e,f,g,h;
    while(n--){
      cin>>a>>b>>c>>d;
      cin>>e>>f>>g>>h;????
      cout<<a*e-b*f-c*g-d*h<< " " << 
      a*f+b*e+c*h-d*g<< " " <<
      a*g-b*h+c*e+d*f<< " " << 
      a*h+b*g-c*f+d*e<< endl;
    }
  }
}