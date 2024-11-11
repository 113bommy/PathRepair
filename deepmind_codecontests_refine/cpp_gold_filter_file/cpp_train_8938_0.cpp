#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define ld long double
#define forever while(true)
//#define 

  int main(){
string a;
while(cin>>a)
{ 
bool owin=false;
bool xwin=false;
if(a[0]==a[1]&&a[1]==a[2]){
if(a[0]=='o'){owin=true;}
else if(a[0]=='x'){xwin=true;}
}
if(a[3]==a[4]&&a[5]==a[4]){
if(a[4]=='o'){owin=true;}
else if(a[4]=='x'){xwin=true;}
}
if(a[6]==a[7]&&a[7]==a[8]){
if(a[6]=='o'){owin=true;}
else if(a[6]=='x'){xwin=true;}
}
if(a[0]==a[4]&&a[4]==a[8]){
if(a[0]=='o'){owin=true;}
else if(a[0]=='x'){xwin=true;}
}
if(a[4]==a[6]&&a[4]==a[2]){
if(a[4]=='o'){owin=true;}
else if(a[6]=='x'){xwin=true;}
}
if(a[0]==a[3]&&a[3]==a[6]){
if(a[0]=='o'){owin=true;}
else if(a[0]=='x'){xwin=true;}
}
if(a[4]==a[1]&&a[4]==a[7]){
if(a[1]=='o'){owin=true;}
else if(a[1]=='x'){xwin=true;}
}
if(a[2]==a[5]&&a[8]==a[2]){
if(a[2]=='o'){owin=true;}
else if(a[5]=='x'){xwin=true;}
}
if(owin){cout<<"o"<<endl;}
else if(xwin){cout<<"x"<<endl;}
else{cout<<"d"<<endl;}
}return 0;
}
