#include<iostream>
using namespace std;

int main()
{
 int a,b,n;
 while(cin>>n, n)
 {
  int x=0, y=0;
 while(n--)
 {
   cin>>a>>b;
   if(a<b) {y+=a+b;}
   else if(a>b) {x+=a+b;}
   else {x+=a; y+=b;}
  }

 cout<<x<<" "<<y<<endl;
}
}
 
 
   
  