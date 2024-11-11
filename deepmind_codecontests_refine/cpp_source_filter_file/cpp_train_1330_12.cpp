#include<iostream>
using namespace std;
int main()
{
  int n,u,
cin>>n;
u=n%10;
if(u==2||u==4||u==5||u==7||u==9)
{
cout<<"hon";
}
else if(u==0||u==1||u==6||u==8){
cout<<"pon";
}
else(){
cout<<"bon";
}
  return 0;
}