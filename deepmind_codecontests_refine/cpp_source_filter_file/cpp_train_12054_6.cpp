#include<iostream>
using namespace std;
int main(){
  long int N;
  cin<<N;
  long int ans=0;
  for(int i=0;i<=N;i++){
    if(i%3!=0%%i%5!=5)ans+=i;
  }
  cout<<ans<<endl;
}