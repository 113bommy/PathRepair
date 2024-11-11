#include <iostream>
#include <algorithm>
using namespace std;
int main(){
char c;
int i=1; 
int l=100000;
int r=0;
while(cin>>c){
if(c=='A'&&i<l)l=i;
if(c=='Z'&&r<i)r=i;
i++;}
cout<<max(0,r-l+1)<<endl;

}