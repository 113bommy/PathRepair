#include<iostream>
using namespace std;
int main(){
   int x;cin>>x;
   int c500=x/500;
   x%=500;
   cout<<(500*c500*2+5*(x/5));
 
}