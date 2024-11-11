#include<iostream>
using namespace std;

int main(){
int H,W;
while(1){
cin>>H>>W;
if(H==0&&W==0) break;
for(int i=0;i<H;i++){
for(int h=0;h<W;h++){
if((i+h)%2==0)cout<<"#";
else if((i+h)%2==1)cout<<".";
}
cout<<endl;
}
cout<<endl;
}
}