#include<iostream>
using namespace std;
int main(){
  int x;
  cin>>x;
  long long c=0;
  for(int i=0;i<1000000;i++){
    c+=i;
    if(c>=x){cout <<i<<endl;break;}
  }

}