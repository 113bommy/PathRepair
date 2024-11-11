#include <iostream>
using namespace std;
int main(){
  long long n,ans=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    if(i%3!=0&&i%5!=0){
      ans+=i;
    }
  }
  cout<<i<<endl;
}